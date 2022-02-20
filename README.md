# AthenaHacks2022
Get Nailed

# Inspiration
We've all faced the struggle of painting our nails, especially our non-dominant hand.  Get Nailed solves effortless painting of both hands! It can even allow you to multitask while you wait to get your nails painted!

# What it does
Our project detects when a finger is placed, adjusts to the correct position, and paints the nail until all nails are complete. In between each nail, a conveyor under the table moves the brush to the nail paint where it can redip so each nail is fresh!

# How we built it
We built this project with Arduino, a few 3D printed parts, and lots of cardboard. The main parts of this project were the conveyor belt and the nail painting brush. The conveyor belt was made using 2 stepper motors, wooden dowels, and elastic bands to propagate the belt forward. The nail painter was made by mounting a servo motor to a wooden stick apparatus. The servo was attached to a paintbrush that can now mimic the flick motion used to paint a nail. The system is started by the presence of a finger on our finger painting station, we sense this with a capacitive touch sensor. An added feature is the LED animations that run in the box as your nail gets painted. 

# Challenges we ran into
One challenge we ran into was calibrating the right 'flick' motion to fully paint a nail. Another big issue was being able to get the conveyor belt to move. Many times it seemed the motors weren't strong enough, there wasn't enough tension, or the rubber bands would bunch up and stop the movement. The belt was super hard to get working consistently and required constant human intervention during the early stages of development. Some of the fixes we tried were different ways to attach the rubber bands to the dowels i.e. having one long rubber band go all the way over or having several smaller rubber bands attached in steps throughout. We also tried several solutions to get the sticks to stay straight in the middle to stop them from going wayward due to the tension. These included creating holders out of cardboard, clay moulds that would double as bearings, designing a Solidworks part that ended up being too long of a print, and our chosen solution of using smaller dowels to create little windows on the other side for the big dowels to sit in.

# Accomplishments that we're proud of
Being able to set up the machine in a way that it is able to successfully find the nail each time. Calibrating the machine was very challenging and due to the inconsistency in the belt, it had to be redone several times. Just being able to look at our final project with all the struggles and changes and thinking 'wow this actually works' is our biggest accomplishment.

# What we learned
We enjoyed putting our Arduino knowledge and to the test for this hack.  It was fun to learn how to work with the capacitive touch sensor and incorporate it into our design.  Although the mechanical debug of the machine was sometimes quite frustrating, it was a good challenge and we were satisfied with our solutions in the end.

# What's next for Get Nailed
We would love to make our project be able to rotate about a user's hand so that it can paint every nail without having to change your finger each time. We also want to add a fan to be able to dry your nails as well as an option to pick from different colors or even set a pattern.
