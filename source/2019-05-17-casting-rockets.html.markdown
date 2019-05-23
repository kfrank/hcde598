---
title: Casting Rockets
date: 2019-05-17 02:20 UTC
tags:
img: assignment6/IMG_2662.JPG
---

I made Saturn V rockets.

## Documentation

- [.stl model (sourced off Thingaverse)](https://www.thingiverse.com/thing:3416703)
- [Rhino mold](/hcde598/documentation/casting/saturnv-mold.3dm)
- [Stl mold](/hcde598/documentation/casting/saturnv-mold-2.stl)
- [Gcode](/hcde598/documentation/casting/D3_saturnv-mold-3d.gcode)

### Unused documentation

- [Fusion 360](/hcde598/documentation/casting/saturnv-mold.f3d)

## Process

I started out first creating the mold model in Rhino with the intention of milling on machinable wax. When I was searching around, I found out that NASA has a lot of 3D models available already. I downloaded the Saturn V rocket, but realized that it was actually a model that contained all of the separate stages of the rocket. Instead of playing puzzle in three dimensions, I went to thingaverse and borrowed a 3D model of the Saturn V rocket.

In Rhino, I imported the rocket mesh and then created a box around it that was approximately the size of my piece of machineable wax, and then positioned the rocket so that half of it was submerged into the bottom of the box. I decided to create two halves of the rockets to speed up the amount of rockets I could cast.

![Creating the mold in Rhino](assignment6/rhino.png)

I then exported the mold and opened it in Fusion 360 to create toolpaths. After creating a toolpath only using a 1/8 flat mill, I realized that I would not get the level of detail I wanted. I went back to Fusion 360 and added two more tools: a 1/16 & a 1/32. When I imported all three of these toolpaths into Bantam Tools, it estimated it would take 9 hours to complete. Not cool.

![All three toolpaths in Bantam](assignment6/bantam-tools.png)

I decided quickly to not even attempt milling on machinable wax. I then modified my mold model in Rhino to decrease the printed material on the bottom of the box so that it would print quicker. When I imported the model into the Dremel tool, it estimated roughly 3 hours. Much better. I used similar settings to my last print: Medium Quality at 0.2mm and 20% infill.

![Model in Dremel Tools](assignment6/3D-print.png)

I then sent my gcode file to the Dremel printers at the MILL with 230° filament and 55° plate settings. It printed great in about three hours.

![3D printing](assignment6/IMG_2629.JPG)
![3D print mold](assignment6/IMG_2630.JPG)

Back home, I mixed equal parts of both liquids to make the Oomoo mold. Originally I was thinking, oh great, since I have two sides, I might be able to put them together to make a two part mold. Unfortunately, the Ooomoo wasn't quite precise when drying, even though the 3d print looked much more precise. I decided at that point to not attempt to create a sprue on these molds and just stick with flat rockets which would look great on a tabletop.

![Setting the mold](assignment6/IMG_2638.JPG)

I used a small, very dull paring knife to carefully pull my mold out. Part of one mold didn't quite set completely on one of the engines, but it actually didn't end up mattering when I went to cast.

I mixed 3 parts plaster to 1 part water and filled my molds.

![Filled molds](assignment6/IMG_2640.JPG)

It took some thought to know how to seperate the dried plaster from the mold without breaking the plaster. I figured out that pulling the mold apart on the sides of the rocket first and then the top and bottom helped get them out the best.

![Plaster Saturn V](assignment6/IMG_2662.JPG)
![Multiples](assignment6/IMG_2679.JPG)

## Reflection

To make the model even more smooth, I probably would sand down the rocket inside the model. I'd also want to print one rocket much larger to make setting the plaster and getting it out of the mold easier.
