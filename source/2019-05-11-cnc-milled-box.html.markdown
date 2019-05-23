---
title: CNC Milled Box
date: 2019-05-11 15:02 UTC
tags:
img: assignment5/IMG_2610.jpg
---

I decided to make a box with tabs for the sides to fit together and grooves for the top and bottom. This allows the top to slide out to access the contents of the box.

![Sketching out the plan](assignment5/IMG_2614.jpeg)

## Documentation

### Rhino & Illustrator

- [Rhino](/hcde598/documentation/cnc-box/cnc-box.3dm)
- [Illustrator](/hcde598/documentation/cnc-box/cnc-box.Ai)

### Bantam Tools

- [Long Sides with Tab Cutouts and Grooves](/hcde598/documentation/cnc-box/side-long-2.btm)
- [Short Sides with Tabs and Grooves](/hcde598/documentation/cnc-box/side-short-2.btm)
- [Top and Bottom](/hcde598/documentation/cnc-box/topbottom.btm)

## Making the shapes

I started out generating the shapes in Grasshopper so I could control the size better. From there, I baked all the sides in Rhino, filleted the tabs, and then created the top and bottom pieces based on the length of the groove plus an allowance for material thickness.

![Starting in Grasshopper](assignment5/grasshopper.png)
_Generating box sides in Grasshopper_

![Shapes built in Rhino](assignment5/rhino.png)
_From top left, clockwise: Top of box, bottom of box, short side (purple line is a groove), long side (purple lines are grooves), short side._

I ended up modifying my original side design allow the top to overhang the short side with the cut out tab to make sliding the top out easier.

## Setting up files

I exported the shapes in Rhino and opened them in Illustrator so that I could make detailed modifications and then export each side as an svg. When saving svgs, I decided to save each shape part as an individual svg to import into the Bantam Tools software. This also allowed me to set different mill tool preferences for each part. The tab cutouts on the long sides needed a 1/64 size mill tool while the rest of the parts could be done mostly with a 1/16 size. I also left a little overhang on the engraved cutouts so that the top would be able to slide properly.

![Short sides in Bantam](assignment5/bantam.png)
_The short sides with a little overhand for the groove._

It was actually really straightforward to set up the mill and put in my pieces. I didn't have any problems here.

![Mill milling](assignment5/IMG_2608.jpg)

![Cutting out the large sides](assignment5/IMG_2607.jpg)

## Box, Assembled

Magically, all my math was correct and the box fit together. <i class="em em-tada"></i>

![Final box, together](assignment5/IMG_2609.jpg)

![Top](assignment5/IMG_2610.jpg)

![Top pulled out](assignment5/IMG_2611.jpg)
