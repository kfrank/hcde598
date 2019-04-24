---
title: Parametric Kit
date: 2019-04-23 02:26 UTC
tags:
img: assignment2/triangles3.gif
---

_It sticks together, yay <i class="em em-smile"></i>_

- [Rhino file](http://klare.io/hcde598/documentation/rhino-grasshopper/cutout-triangles-kit.3dm)
- [Illustrator file](http://klare.io/hcde598/documentation/rhino-grasshopper/cutout-triangles-kit.ai)
- [Grasshopper source code](http://klare.io/hcde598/documentation/rhino-grasshopper/cutout-triangles-kit.gh)

![Assembled](assignment2/IMG_2452.jpg)

## Designing the kit

I turned to my own company, CodePen, for inspiration since there tend to be a lot of geometric designs created, even if they're mostly interactive. I thought this one was cool since it had sets of solid and outlined triangles intersected at seemingly random degrees. I used this concept to create triangles with random intersections which created cut-outs of various polygons inside a triangle.

I also had some plywood lying around from previous projects (much more than cardboard), so I used that with a new acrylic sheet to give the kit some color.

<p class="codepen" data-height="387" data-theme-id="0" data-default-tab="result" data-user="yuanchuan" data-slug-hash="YLyEvb" style="height: 387px; box-sizing: border-box; display: flex; align-items: center; justify-content: center; border: 2px solid black; margin: 1em 0; padding: 1em;" data-pen-title="Unicode triangles">
  <span>See the Pen <a href="https://codepen.io/yuanchuan/pen/YLyEvb/">
  Unicode triangles</a> by yuanchuan (<a href="https://codepen.io/yuanchuan">@yuanchuan</a>)
  on <a href="https://codepen.io">CodePen</a>.</span>
</p>
<script async src="https://static.codepen.io/assets/embed/ei.js"></script>

## Generating the shapes with Grasshopper in Rhino

My first attempt at this was to use triangulate to generate a grid of triangles and then use the first triangle's three points to calculate an inner triangle which was duplicated in a rectangular array. While this strategy did work and allowed me to keep the size relative for both triangles, it proved stressful when trying to generate notch connectors for every side of the larger triangle. (See details in the issues section below).

I scrapped that idea and instead tried to approach this by creating one triangle from a polyline using trigonometry to make it perfectly equilateral. From there, I created notches with a slider to change the width corresponding to material thickness and polar arrayed the rectangular notches around the center of the triangle. I then used arrays to duplicate the triangles into a controlled grid set up to match my material size (12" x 12").

This strategy worked much better for actually giving me shapes I could then manipulate and print from, but it still had a ton of issues.

### Issues

Even as someone who thinks through problems for programming on a regular basis, there were things Grasshopper did that were highly annoying and I would’ve saved hours of my life just doing them in illustrator. I did countless hours of Googling and searching through the Grasshopper forums, like in real life as a developer but 10x worse.

![Confused Meme](assignment2/2zcjhn.jpg)

#### <i class="em em-upside_down_face"></i> Triangulate is annoying

Using triangulate somehow made things extremely annoying. Generating notches for all the outer triangle sides required calculating the exact angle relative to X and corresponding each angle to a xy plane relative to the midpoint of each triangle edge. I actually _did_ get this to work and generate triangles in the right places, but when I baked everything, I was given about 5x the amount of notches, most on top of one another. This would not have been great to send to a laser cutter, as it would've made passes for each drawn curve. Even debugging by getting the list length of variables at different steps didn't exactly lead to figuring out why I was getting so many notches. I probably spent 2-3 hours just trying to figure this out. It still didn't work when I turned graft off and collapsed the tree, so idk. <i class="em em-woman-shrugging"></i>

![Triangulate notches for all](assignment2/notches-for-all.png)

#### <i class="em em-cry"></i> "Random" isn't random at all

In my optimism, I wanted to use Grasshopper to generate everything in my design, including the bisecting lines for the inner triangles. The only issue was that I wanted this to be unique for every triangle, no matter how many triangles got generated. This is where I re-learned that every "random" function in programming isn't really random; it just chooses from a seemingly random list of numbers, but on each iteration, follows the same pattern. I also ran into this issue when working on my led light strip for Physical Prototyping. The screenshot below got pretty close, but it still wasn't the best. If you look closely, you definitely see a pattern. Also, wtf was up with the very last triangle getting ALL the lines. Not bisecting at all. <i class="em em-woman-gesturing-no"></i>

!["Randomizing" lines for inner triangle cut-outs](assignment2/randomize-lines.png)

#### <i class="em em-woman-facepalming"></i> Fillet does all corners

I _really_ wanted to fillet the corners where the notches connect to make a smooth and satisfying connection when assembling the kit. Using the standard fillet function ended up filleting _ALL_ the corners, which would've meant a loose connection on the very inside of the notches. No good. I turned to using the other fillet function, which fillets on only one curve and set a Boolean list to specify which ones I wanted filleted. Turns out this creates a new curve for _EVERY_ filleted edge. Also no good.

I kind of just gave up on this one, though when I was in the makerspace printing, Andrew informed me that he used a triangle to trim the edges for a custom fillet. This seems like a much better approach to getting a fillet only on the outside, but doesn't still make any sense to me why you can't just modify the fillet function to do what you want. With Andrew's triangle cut-out approach, it did require setting an origin exactly at the midpoint and rotating it the correct degrees, but it worked much better. Since I was printing and spent hours in Grasshopper already, I decided to just cut fillets for the connectors in Illustrator.

![Custom Filleting Issue](assignment2/custom-filleting-issue.png)

### Grasshopper take two

From experiencing all these issues, I _really_ wanted to try to solve generating most everything parametrically in Grasshopper. I think my past failures were not fully understanding when to graft/simplify/flatten trees. When I redid everything with all my new knowledge from past failures, I had a much better time.

![Triangle grid](assignment2/everything.png)
_Yay, it all works much better not doing this at 1am._

#### 1. Create a triangular grid

First, I found the center of each triangle by separating the edges, finding the endpoints of each line, and using one side of the endpoint to calculate the center of each triangle. I set also inputs for each material thickness (I had three).

![Triangle grid](assignment2/inputs.png)

#### 2. Scale the triangles in the grid to create inner triangles

I used the grid as the base geometry, and then set the center using the above calculation to scale triangles down in size, creating inner triangles.

![Triangle grid scale](assignment2/triangular.png)

#### 3. Make notches for connectors

Since the triangles in the grid are not in the same orientation, I divided out the triangles into ones pointed up and ones pointed down. I then used different bisectors from the Incentre function to create straight notches on all triangles first. I then polar arrayed the straight notches around the center of the triangles for the other two sides.

![Making notches for both up and down triangles](assignment2/make-notches.png)

To make sure each notch was created out from the midpoint, I used the construct domain function to set expressions to size the straight notches on the xy plane.

![Using Construct Domain to set expressions](assignment2/construct-domain.png)

#### 4. Creating the connector piece

To create the connector piece, I first created a rectangle 4x the size of the notches. Using the construct domain function again, I created inner rectangles aligned to the left and right of the triangle taking the inputs for each material size. I then used the region difference function to create the entire connector.

![Creating straight connectors](assignment2/connector.png)

#### 5. Creating 15°, 30°, and 45° connector pieces

I create a new rectangle half the width of the connector and used that to separate it into two sides. To do this, I made sure to set the origin of rotation at the bottom center point of the connector using the Box Corners function to find each corner. I then rotated each connector by increasing amounts of 15°.

![Rotating the angled connectors](assignment2/angled-connectors.png)

To join the left angled side and the right non-angled side, I first separated all the sides. I then found the top right corner of the angled side and the top left corner of the non-angled side, and created a line between the two points. I then joined all three curves, using flatten trees.

![Joining the angled connectors](assignment2/join-connectors.png)

#### 6. Bisecting the triangles to create inner polygons

I baked both the triangles into Rhino and created the bisecting lines by hand to make sure they were all truly unique for each set of triangles. I used a line and checked 'On curve' to make sure it would snap to each inner triangle. I then used trim to select which half I wanted to delete. I then joined all the (now) inner polygon curves.

![Inner polygons](assignment2/polygons.png)

#### 7. Setting the shapes up for printing

I then set the shapes to different layers to allow printing at different settings on different materials. I actually ended up combining the inner polygons and outer triangles to create two sets of shapes so that the acrylic and wood pieces would be different.

![Dividing the shapes into layers for different printing](assignment2/layers.png)

## Printing

I had set up my units in Rhino to be in inches to match everything else and checked the 1 to 1 matching on the export box, so I didn't run into any sizing issues like my classmates who were in the Mill at the same time as me. They didn't seem to have an issue once they set everything to inches as well. I actually exported everything to Illustrator so I could be damn sure it would print at the correct size.

I set up a test layer with four connector pieces in different colors and then color mapped them to a range of values to find the best setting for each material. This also allowed me to test the connection between materials. I found it to be a bit loose at first and reduced the size of the notch rectangles by 0.05 inches for each side.

I masked the plywood and left the protective film on the acrylic sheets to reduce the burnt haze on the wood. I probably should've masked the clear sheet since it had only a clear protector and should've masked the back of the plywood.

![Laser cutting more triangles](assignment2/triangles2.gif)
_Laser cutting is still very satisfying to watch and way easier than hand sawing through this plywood_

![Triangles](assignment2/IMG_2442.JPG)
_Pieces all piled up in the makerspace after printing_

![Triangles](assignment2/IMG_2445.JPG)
_:D Yay, awesome colors!_

![Little Burnt Notches](assignment2/IMG_2438.JPG)
_Should've masked this sheet, oh well, they’re pretty tiny_

### Settings

The final settings I used to print my materials.

#### Clear & Neon Acrylic

.06" Thick & .118" Thick

Speed: 14, Power: 100, Frequency: 50

I tested both acrylic sheets since their thickness varied, but found the same setting to be good for both. This setting had a very satisfying "snap out" quality on the neon acrylic, which also ensured the pieces didn't all fall below the laser cutter’s grid.

#### Plywood

0.196" Thick

Speed: 10, Power: 100, Frequency: 50

## Future Considerations

1. Trimming overlapping triangle lines to reduce duplicate cuts
2. Masking the clear acrylic
3. Not spending so many damn hours in Grasshopper trying to get it to generate everything.
