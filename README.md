# C++ Unreal Engine Project - Slash

- Working on an Unreal Engine project for fun on the weekends to take a break from full-stack work and improve my C++.  Interests are in full-stack development, not necessarily game dev, but might be a fun hobby on the side.
- Following Stephen Ulibarri's Udemy course - Unreal Engine 5 C++ The Ultimate Game Developer Course and will eventually spin off from it.  


![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/208f0130-b374-43ae-ba4a-9a366ed9be85)

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/176ac922-478f-43d1-b0da-a7da6f26d37f)

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/7eb8966a-9d87-46ea-b4c1-f68c1d880788)

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/32eefb2a-7a28-4658-89a4-871e0791f376)

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/34891953-1113-4c22-a403-909a19af3ee6)


* Get rotation vectors so character will move according to camera boom rotated direction.

  ![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/fc5679e0-873a-4c90-ab6c-47a633df0a87)

* Camera boom set up using character of "Echo" from Unreal Project Valley of the Ancients - per the tutorial.
  
![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/f4ba59ca-1162-47df-a66b-cb242afc68f0)

* Setting up animations via Blueprint (non C++) using state machines to toggle between walking/running animation based on GroundSpeed variable.

  ![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/b433c64e-10ec-46b8-b4db-8176a6f1fa41)

* Also set up running/walking animation state changes with equivalent C++ code:

  ![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/e2a0cf0a-bf89-4580-a2e8-eb1166db8699)
![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/a7014223-12d3-4ab3-baec-b64c70606a02)


*Inverse kinematics (IK) for standing on sloped surfaces to move foot bone effectors based on a sphere trace.


![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/512f56ff-db7d-44f9-b171-99006d1ff3b1)

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/188b9f18-8201-41d5-8deb-727e8c5fd8dd)

* Now feet are positioned correctly when standing on a sloped surface such as a hill.  Character used is "Echo" per the Udemy course from the Valley of The Ancients Unreal Engine Demo.
![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/d87c6052-9786-4e2f-aad4-26bf800b946f)

  
* Added sword prop with a sphere component for overlap events in C++ (will eventually be able to equip sword if overlapping the sphere mesh).

  ![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/04314da7-df07-4399-8318-4da1c106e5c7)

  ![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/2db65602-278a-4965-8d57-85a722b0dbb8)

* Creating an IK (Inverse Kinematics rig to map maximo animations to other character:
  * Forward Kinematics (FK): In FK, you specify the rotation and position of each joint or bone in a limb directly. For example, if you're animating an arm, you would manually set the rotation of the shoulder, then the elbow, and finally the wrist. This can be cumbersome for creating natural poses.

  * Inverse Kinematics (IK): In IK, you specify the position of the end effector (e.g., the hand) first, and the system calculates the rotations of the joints in the limb to reach that position. This allows for more natural and efficient posing, especially for tasks like grabbing objects or walking.

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/208c5f9f-2add-4a8c-a2a2-f30631883908)

  

* Added an IK rig and retargeter to map a downloaded animation/skeleton to Echo skeleton.  This involved adding retarget chains manually to the skeletons of each body (the downloaded mesh with downloaded animations) and Echo character, to map corresponding body parts to one another (e.g- fingers, arms, legs).  So an animation built for one character can be used for the Echo character or adapted.

  ![test](https://github.com/Mike11199/unreal-project-slash/assets/91037796/93e56cc3-0040-457f-bf8b-67405600e73c)
  ![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/e12a8797-7a23-4b63-949b-dc7366e9b674)


<br />
<br />
<br />

  * C++ code for attaching sword to character mesh when overlapping with the sword's sphere mesh and pressing the "E" button.  Calls superclass item.cpp's OnSphereOverlap function.

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/aaec376d-a951-40f6-98a9-5292f035a2da)

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/02d9c723-545e-4be9-bb05-8f5f6328c93b)

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/588c86a9-f83a-4ac6-bbb1-4f86a8671708)

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/1d3b54da-de87-4254-baa7-8d11b3f91a04)

<br />

* Implemented a hit interface that enemies can inherit from.  This allows the weapon class to call an actor's get hit function, by casting the actor to the hit interface.  If the cast is succesful and not null, we know the actor inherits from that interface, and can implement their own hit function.  This is useful as the wepon class doesn't need to know what it hit and define a body for getHit() for each enemy in the world.

* Instead, each enemy implements their own override of the getHit function they inherit from the hit interface.  The hit interface also receives the hit location from the weapon's sphere trace, which determines the hit location and impact point.

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/8d9171e9-2c2d-49df-8c83-49b2419e5a1c)

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/a246ebcb-7524-443c-858c-97e1d1b95f17)

<br />
<br />

* Used Vector Math to calculate the Dot Product between two vectors, or the angele between the impact point of a weapon strike and the enemy's forward vector (direction they are facing).  This angle (Theta) determines which hit react animation to play, so the enemy stumbles in the right direction.

<br />

* We also calculate the Cross Product to know if we are hit from the left or right, as the Dot Product always returns a positive value.  The Cross Product, whether it points up or down in its Z axis, is used to decide if we multiple Theta by -1, which indicates if the angle is obtuse or acute.

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/b9bab661-667a-4a2b-a9ca-7292e68dab80)

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/7f320ca8-1af6-4e7b-8566-ad993e0c3a12)

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/d027736f-dd63-4ba5-a43e-02fe6c35fc11)

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/6829ddf3-9a6c-4994-96a9-18db5e39c0f7)



