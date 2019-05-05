---
title: Gear Assembly
date: 2019-05-05 20:48 UTC
tags:
img: assignment4/gears.JPG
---

For this assignment, I had two goals in mind:

- Spend the least amount of time in the MILL.
- Start with a base assembly that fulfills the assignment and then add a challenging stretch goal on to it.

I didn't want a repeat of last week where I spent 9 and a half hours in the MILL and had some strong anxiety. This week, I only spent 3 hours in the mill and most of that time I was working while waiting for my 3D print to finish. I probably only spent 30 minutes actively laser cutting or setting up the 3D printer, which I'd call a win based on good planning and some luck.

## Documentation

- [OnShape Model](https://cad.onshape.com/documents/1733a3f48a16a99259e4a93e/w/6e427e999e67f320646f689c/e/16f4c02966ac4d06ccea2547)

- [Laser Cut File](documentation/to_laser_cut.ai)
- [3D Printed Base](documentation/D3_base.gcode)
- [3D Printed Gear](documentation/D3_center-gear.gcode)

## Design

For this assignment, I first started with a two part gear assembly with one 3d printed gear and one laser cut gear. I intended to laser cut all flat parts and 3D print other parts. The smaller center gear was to be 3D printed because I designed it with a cylinder on the top which would fit over a dowel (the point of rotation origin) and connect to a hand turner on top.

I then added on to the assembly by making it a three part gear assembly with an outer internal spur gear with arrows attached along the outside. These arrows would rotate on a pin and would flip over when the encountered a long dowel sticking out underneath and past the outer gear. In the below screenshot, the part to the left of the yellow arrow is the long dowel used to flip the arrow's direction.

![Creating the parts in OnShape](assignment4/onshape.png)
_All the parts mostly aligned_

I found OnShape much easier to use and design in than Rhino. It seemed to mesh more with how my brain things through assembling parts. I especially liked that you could test out all the parts before even fabricating them, something I tried to do in Rhino but couldn't. Below, you can see the three gears spinning together in the assembly. (I didn't connect the arrows to the outer wheel here.)

![Creating the assembly in OnShape](assignment4/assembly1.gif)
_Testing out the gears._

Being able to have all the parts listed automatically in a bill of materials helped me a lot in keeping organized and having a plan for when I got to the MILL. I added a column for how each part would be fabricated (or if it was sourced), and then another for any post-processing I planned.

![Bill of Materials](assignment4/bom.png)
_Listing out methods of fabrication and post-processing for all the parts._

## Fabrication and assembly

I started the 3D printed base first when I got to the MILL since that would take the longest. Surprisingly, I didn't have any prints fail!

![3D printing the base](assignment4/IMG_2521.JPG)
_Base with slots for two pegs for the inner gears._

I exported all the flat pieces as .DXF files and assembled them all into Illustrator together. Like my previous projects, I laser cut on wood again because that's what I had already available.

![Laser cut](assignment4/laser-cut.png)
_Flat pieces to laser cut from wood._

I ended up sourcing some [wooden dowels](https://www.amazon.com/gp/product/B07H58Z6HH/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1) that were 10mm in diameter because that's what the default center bore diameter happened to be in OnShape. These fit really nice in the base. I ended up sanding down part of the middle dowel to make the spinning interaction even more smooth. Yay for having wooden dowels to do this with.

The major trouble I encountered was that the piece I laser cut for the hand turner wasn't quite large enough to fit over the top of the 3D printed inner gear. Even after sanding down the hole for the turner and the outside of the gear, I thought I got it to be enough but broke the piece trying to fit it on top. <i class="em em-frowning"></i> Next time I'll probably just make both parts together and 3D print them both so I know they'll be the right dimensions. It's a bit hard to tell when you're trying not to wait 2 hours for a 3D print to finish before laser cutting.

Good thing the assembly still works pretty well by spinning the inner gear.

![Inner gear](assignment4/IMG_2532.JPG)
_You can see where I sanded down the top of the inner gear to get the turner to fit before I broke that part._

![Inner gears](assignment4/2-gear.gif)
_The gear assembly in action. Pretty satisfying to spin! I’ll say definitely intentional, smooth, and robust. <i class="em em-smile"></i>_

## Stretch goals

For the challenge part of this, I wanted to see if I could get the interally toothed gear working to flip some arrows. Unfortunately, since I already cut out the piece, it was hard for me to find true center. I used some thread to find it and then confirmed with my calipers.

I was planning on screwing the piece to connect the outer gear to the center, but didn't anticipate my wood being so brittle. I splintered it too much and had to use wood glue and a clamp to attach this part.

![Finding the center of the outer gear](assignment4/IMG_2568.JPG)
_Using string to find the true center._

I didn't really have time to source pins to use, so I made do with some nails instead. I used a slightly larger drill bit than the nails so that the arrows could pivot. I messed up drilling straight through the center of the wood a few times (thicker wood would've helped here). I then attached a few of the arrows around the outer gear to test turning, though this too was hard due to how fragile the wooden gear was. I probably wouldn't use wood again for making small moving parts.

![Setting up the arrows](assignment4/IMG_2569.JPG)
_Arrows drilled with nails as pins._

I used a drill bit as my arrow turner instead of trying to find something to source since it was long enough and I knew it would stay put for me to test out the interaction. (You can see it sticking out of the peg in the base on the right in the below image.)

![All the parts](assignment4/IMG_2594.JPG)
_The major parts disassembled._

I had a bit of difficulty trying to figure out the proper point to put the pivot nails in the arrow. Some of them worked great, and others took more force to turn. Again, if I had more time for this assignment, I probably would've used a different material for the outer gear and the connectors to the arrows. I couldn't find any information on how to create this interaction in the assembly in OnShape. The software ignored objects colliding with one another, which is kind of the point of this interaction. Being able to prototype that would've saved me a lot of fiddling.

You can see at the bottom of the below gif one of the arrows flipping over the drill bit turner. Yay, it works!

![Spinning the wheel](assignment4/outer-wheel.gif)
_This is really hard to spin and keep a camera straight at the same time._
