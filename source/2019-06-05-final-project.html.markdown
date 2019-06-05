---
title: Final Project
date: 2019-06-05 15:20 UTC
tags:
img: assignment7/final4.jpg
---

![Testing out the cam on the servo](assignment7/final.gif)

_Final piece_

# Concept

A shadowbox art piece that captures the sky over the Olympic Mountains. For reference: here is an image of sunrise over the Olympic Mountains from Capitol Hill.

![Sunrise over the Olympics](assignment7/sunrise.jpg)

I wanted to use leds and different color and translucencies of acrylic to create this effect, and also move mountains! The initial idea to put three sets of mountains on cam was because the colors of mountains were not easily created by shining leds through acrylic. They're different colors at different times of the day, so why not have different sets of ranges move to accomodate that.

![OnShape Assembly](assignment7/onshape-assembly.png)
_OnShape Assembly from Planning_

# Bill of Materials

To complete this project, I ended up using:

- 3 24" x 12" sheets of translucent white acrylic
- 1 24" x 12" sheet of black acrylic
- 2 12" x 12" sheets of clear blue acrylic
- 1 1/4" diameter wood dowel
- Gray PLA Filament
- 1 8' x 6" poplar board
- 5 36" x 3/4" straight dowels
- Nails & Nail gun
- Wood glue
- 2 angle braces + 4 screws each
- 1 individually addressable LED string
- 1 Arduino Uno
- 1 5V batter
- 1 5V outlet to battery pack connector with on/off switch

###Original Bill of Materials from Project Planning:

![Original Bill of Materials](assignment7/bom.png)

# File creation

How I created everything.

## 1. LED Grid

I started out from the back of the piece by creating the grid each LED would sit in by parametrically generating circles that were the diameter of the LEDs. I did this in case I needed to quickly change the diameter after doing a test run of laser cutting the acrylic to account for tolerance.

![Grasshopper](assignment7/grasshopper.png)

I then baked the light cut outs and exported everything as a .dxf file to import it with all my laser cut pieces into Illustrator.

## 2. Mountains and Foreground

To create the mountains, I imported a screencapture from the app PeakFinder on my phone into Illustrator. I then used the image trace feature to turn the screencapture into a vector and manually isolated the silhouette of the Olympic range.

![Peakfinder screenshot](assignment7/peakfinder-screenshot.jpg)

## 3. Cam mechanism

I created the Cam Mechanism in OnShape by importing the .dxf of the light grid and the mountain range I created in Illustrator. I then adjusted everything on an axel that was the size of the 1/4" wooden dowel I would use in the assembly to get the right shape. I exported the face of the cam as a .dxf to import into my laser cutting file in Illustrator.

In the same assembly, I created followers which would attach to the laser cut mountain rangers to give more stability as the cam rotated. I exported these as .stl files to import to Dremel's 3D printing software to print.

Additionally, I created an axel holder for the front of the mechanism which would be glued onto the back side of the foreground to provide proper placement for the cam mechanism.

![OnShape Assembly](assignment7/cams-onshape.png)

## 4. LEDs

Even though I created a [program to create light sequences with LED strings](https://github.com/kfrank/gitbit) in Arduino, I actually decided not to use it and opted for simpler code which would fade from blue to orange and then back. I mostly did this because I ran out of time at the end.

[Reference code used](https://forum.arduino.cc/index.php?topic=418923.msg2886563#msg2886563)

### Servo

I ended up attaching the cam to the servo and did a test through the Arduino examples, but didn't actually end up hooking this up.

![Testing out the cam on the servo](assignment7/cam.gif)

# Assembling

Laser cutting and 3D printing went pretty smoothly. I actually showed up before our second to last class at the MILL and printed everything while no one was there. Nothing caught on fire, and when I had all my pieces stand up to test how they would look, I was pretty happy with it.

![Visual Acrylic Layer test](assignment7/testing-layers.JPG)

## 1. Laser cutting

I used my old acrylic settings of 10 speed, 100 power, 50 frequency to cut.

![Mountains](assignment7/laser-cut-mountains.JPG)

## 2. 3D printing

One of the printers I was using jammed halfway through printing the second cam, but we got it unstuck and started printing just fine again. Since I had some time, I pulled an arduino enclosure off of Thingaverse and printed the bottom of it so I could more easily connect my arduino the the back of the piece.

## 3. Frame

Now here's where things got tricky.

I moved last Friday.

All my stuff got packed up, I actually didn't lose anything from the this project, thankfully, but it was ALL OVER the place. There's still boxes everywhere in what will become my office.

My original plan was the go to the Fluke Makerspace on Friday evening to attend the woodshop and then miter cut my wood and cut grooves in it (hopefully with a table saw).

Since I moved Friday and had my life upended, I missed out by like half an hour because of traffic from my new place. Awesome.

My back up plan, however, was to visit the West Seattle Tool Library and rent a miter saw and a router to make the frame.

![Tool Library](assignment7/tool-library.JPG)

Of course, despite making a very cool guide for my router, I had way too many things nailed down and I still failed at getting stright grooves.

![Failed routing](assignment7/failed-routing.JPG)

For my next attempt, I cut some grooves using my Dremel multi-tool in wood. They were grooves all right, but not straight, and definitely didn't fit any acrylic in place. That idea also got scraped.

![Grooves](assignment7/grooves.JPG)

For the third attempt, I went back to Home Depot and picked up some more wood and straight dowels to use to create grooves. I figured I could use my nail gun and some wood glue to get the dowels in place to hold the acrylic. Except my miter saw was weird and I couldn't figure out how to change the angle of the blade since my wood was now 6", too tall to fit under the saw. I just made some straight cuts instead and moved on.

![Third attempt](assignment7/grooves-take-2.JPG)
![Testing straight dowels](assignment7/testing-fit.JPG)

Yay, it finally worked.

## 4. Post-process

![Spray painting the LED grid](assignment7/mirror-coating.JPG)

While I was going crazy with the saw and some wood glue, I was waiting for some spray paint to dry on the LED side of my LED grid. This gives the acrylic a much more reflective surface to have the light bounce off of. Which I needed because I used really huge LEDs instead of being a smart person and just ordering new strings with small ones and using more of them.

## 5. Putting it together

Finally.

All the LEDs got popped into their individual holes in the grid.

![LEDs](assignment7/assembling-leds.JPG)

Each layer of acrylic got fit into the sides with the grooves and then the bottom was nailed on.

![Layers](assignment7/layers.JPG)

This would've been great, but I ended up breaking my cam axel assembling everything. Since I couldn't find my dowels because of moving, I just decided to go with non-moving ranges and glued them into place at different heights to create a nice effect.

![Cams](assignment7/cam-underneath.JPG)

![Cam attachment](assignment7/cam-servo-attachment.JPG)

I threw up the NeoPixel test to see how it would look. Ok, the light goes through the acrylic, but again, since I wasn't being a sane person, the lights gave an abstract grid-y look instead of the fluid gradient look I was going for.

![Testing out the leds](assignment7/testing-leds.JPG)

I nailed on the top instead and threw up a blue to orange color swipe with NeoPixel and called this prototype done. Even though it's not exactly what I was going for, I still think it looks cool.

![Testing out the leds](assignment7/final5.JPG)
![Testing out the leds](assignment7/final2.jpg)
![Testing out the leds](assignment7/final1.JPG)

# Reflection

##1. The wood frame

Maybe this would've been easier if I would've been able to go to Fluke all along, but I wouldn't have done this the way I did. Improvising cost my hours worth of time I wasn't expecting.

##2. Cam followers longer

When I tested the cam mechanism, the mountains lifted and lowered, but weren't exactly uniformly horizontal. I would've definitely made the followers longer.

##3. Small LED strip

Using smaller LED strips would've made the gradient animation much more subtle and give the effect I was going for.

##4. Experiment with LED lighting from bottom on acrylic

I also came across this method in my research, but wanted to do something different. This technique would've been great to experiment with.

## Source Files

### OnShape

- [Onshape Assembly & Modeling](https://cad.onshape.com/documents/a8e1af7107f956e7db86eb20/w/049e752049c02e10ec8a1439/e/26cb20b70adedc1d48e5dbd8)

### Grasshopper/CAD

LED Grid

- [Parametric LED grid – Grasshopper](/hcde598/documentation/final/working-files/light-grid.gh)
- [Parametric LED grid – Rhino](/hcde598/documentation/final/working-files/light-grid.3dm)

Mountain Ranges

- [Mountains](/hcde598/documentation/final/mountain-black.ai)

### Laser cutting files

[Illustrator](/hcde598/documentation/final/LASER_CUT.ai)

Light Grid
[.dxf](/hcde598/documentation/final/exports/01-light-grid.dxf)

Cam
[.dxf](/hcde598/documentation/final/exports/3-Cam.dxf)

Mountain Ranges
[.dxf](/hcde598/documentation/final/exports/3-mountains.dxf)

Foreground
[.dxf](/hcde598/documentation/final/exports/foreground.dxf)

### 3D model files

Axel Holder
[.gcode](/hcde598/documentation/final/D3_axel-holder.gcode)
[.stl](/hcde598/documentation/final/exports/axel-holder.stl)

Follower
[.gcode](/hcde598/documentation/final/D3_PRINT.gcode)
[.stl](/hcde598/documentation/final/exports/3-follower.stl)

Arduino Enclosure
[via Thingiverse](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=8&cad=rja&uact=8&ved=2ahUKEwj14Z2PqtPiAhXEGTQIHZ8-D7UQFjAHegQIBxAB&url=https%3A%2F%2Fwww.thingiverse.com%2Fthing%3A628929&usg=AOvVaw0RH_-KixUyVANXXO82UBWg)
