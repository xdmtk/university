# Project 1 - Platform Simulation

Since this assignment didn't explicitly list topics to cover in the write up, I'm going to talk mostly 
about my experience with the project, what I learned and what the challenges were. But before I get into
this, a major note that I need to mention for this project: 

### Important Note

While the project is functionally correct (has all the color/position transitions, input key responses,
and meta data for each platform), I realized just yesterday that the code that I wrote is extremely performance
taxing and makes a considerable difference in the actual runtime when executed on different machines.

So far I've been developing this project on my main desktop machine (Ryzen 2700X CPU/Radeon Vega 58 GPU) and 
I haven't noticed any issues with performance. However, I noticed when attempting to make a screen recording of
my project, the framerate on the project got considerably slower. Again the project is still functional but the
movement speeds and color transition speeds of the platforms slow down alot since they are depedent on the main
update loop for the project. 

I decided to try for the first time deploying on my laptop machine to see if the runtime was the same without
any screen-recording, but just on a different machine. The results were that my laptop took the same performance
hit even without any screen-recording. Because of this, I have taken the video demo of my project with my camera phone
and have submitted this as proof on my machine, the deployment works as intended. 

##### Testing

With this being said, if you find that you are getting the same perfomance hit when attempting to run the simulation,
you can actually fix this by modifying the `minimumMovementSpeed` and `maximumMovementSpeed` variables in the script
I've written. Of course adjusting these up on a machine that doesn't suffer from the performance issue would make the 
platforms move up and down/transition colors very very fast. So only do this if you find that you need more proof
than the video I've provided that the project works as intended (on my machine). 

##### Why I Won't Fix

If I had discovered this performance issue much much earlier, I would be inclined to discover the root cause and
attempt to fix it. But because I discovered it as late as I did (and potentially would not actually have discovered 
it at all), I don't have the time to pull apart the code and see where optimizations could be made. The nearest idea
I have regarding the issue relates to where the script actually operates, as in there is only 1 main script that
operates on all of the generated node platforms in one singular location, instead of the design where each node 
has its own separate script operating its behavior. 

##### What I Learned

Since this is my first time using Unity, I learned a considerable amount about how Unity operates, Unity's API in C#,
and how scripts operate against Unity Game Assets. But I think most importantly what I learned during this project
is that "works on my machine" almost always comes back to bite and I should have been testing my build iterations
on multiple machines from the get go, and I would have spotted this performance issue I mentioned much earlier.

##### Challenges

The biggest challenge was simply wrapping my head around the Unity API. Once this was accomplished, the logical 
actions of each platform were very straightforward and relatively easy to implement. 
