# Need 4 Stek
An AI capable of driving a car in a simulator (V-REP PRO EDU)

*This was a school project*

*Note: this project may only work under a Unix environment, the V-REP version provided is the Ubuntu one*

### How the project was built
During this project, we tried for the first time to use a neural network and a genetic algorithm to trie to make a car drive itself in a simulator. Unfortunately, the learning curve was too slow so we have also done a simple algorithm (as a backdoor) capable of driving the car, which is what you will experience if you test this project.

### How to test it
The first step is to compile the source files using `make` in a command prompt

Then, you need to launch the V-REP software
`./V-REP/vrep.sh`

Now you must open one of the scenes located in `scenes/` within V-REP

Finally, just execute the `pipes.sh` script to start the simulation
`./pipes.sh`
