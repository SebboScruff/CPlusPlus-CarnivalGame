/ milestones-SebboScruff
milestones-SebboScruff c/eated by GitHub Classroom

This file will be used to express ideas, reference any external resources used (sprites, audio etc.), and to be a general developer log.

## Milestone 1: Ideas and Planning:
  My 2 unique mechanics will be somewhat linked: I will intend to have some tiles on the map be harmful to stand on (for example, spikes or fire), and then I will have the main
  shooting mechanic have the added effect of propelling the player backwards slightly due to recoil. In this way, I hope to make the game more dynamic in a couple of ways: <br>
    - The player must be cautious of where they are standing as they may fall into spikes after being recoiled backwards.<br>
    - When Enemies are eventually added, the player can take them out without even shooting them by tricking them into walking into the harmful tiles on the ground.<br>
    
## Milestone 2: Fundamental Game Mechanics
  For this milestone, a number of crucial mechanics have been added. Trying in vain to not be distracting by my crippling addiction to Dota 2, I added a tile-based level map
  (currently just aesthetic: the fire floor has no functionality yet as the player has no health :/), as well as basic player controls. Currently, the player can move orthogonally
  as well as shoot, using Arrow Keys and Space respectively. In addition, there is a small text box in the top-right corner of the screen which displays the player's score.
  Again, no actual functionality as of yet, but the framework is there.

## Milestone 3: A Few Gameplay Additions and Code Profiling
  So not a huge amount has happened in terms of mechanical changes since the last milestone, since all the fundamental mechanics are in place. I ran the game for about 2 minutes, 
  checking performance statistics so ensure there were no memory leaks or any bad stuff like that: <br>
  ![Code Profiling as of 09/12/2020](/Misc/profilingExample.png)

## Final Project
  Having had a dramatic change in creative vision in the last hours of production, the theme of the game, in addition to the unique mechanics, were drastically changed. Instead of
  being set in a fiery cave, the game will be set on a carnival ground; in place of generic shooter enemies, the player will fire at moving targets across an impassable barrier.
  One new unique mechanic will be that the player only has a limited number of bullets: once they run out, the game is over!
  
  Final Commit to README: 
  At the end of production, some things went well and others not so much. I'm happy with the way that I implemented what I did, but in terms of actual content, I didn't quite get as much as I would have wanted. In this final product, I couldn't quite get collisions to work properly so there is still no way to actually gain score which is unfortunate - maybe it's just part of the new carnival game aesthetic though, those things are impossible to win.
  After this coursework has been marked, I think I will try to implement the things that I lacked by the deadline - I'm most of the way there already, may as well carry it through.
  
  Location of Final Files: Code and Exe are in the SebScaifeShooterGame Folder:<br>
  SebScaifeShooterGame/Release/SebScaifeShooterGame.exe<br>
  SebScaifeShooterGame/SebScaifeShooterGame for all code (cpp and header) files.

## References and Tutorials:
  Box-To-Circle Tutorial: http://www.jeffreythompson.org/collision-detection/circle-rect.php <br>
  Axis Aligned Bounding Box Tutorial: https://tutorialedge.net/gamedev/aabb-collision-detection-tutorial/ <br>
