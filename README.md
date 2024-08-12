# Links

- [Download Windows v0.0.20 Zip File](https://d29uq875pp3dr.cloudfront.net/Windows_v0.0.20.zip) - 4.7 GB
- [Source Code (C++)](Source/Slash)
- [YouTube - Combat Test](https://www.youtube.com/watch?v=6h0NSLb7Aqw)

- Releases are zip archives of a packaged executable file (.exe) I've uploaded to an Amazon S3 Bucket.  The object is provisioned with CloudFront CDN (Content Delivery Network) rather than making the bucket public (as 1TB a month bandwith is free with CloudFront).
- To run, unzip the archive and simply double click the `.exe` file.
  
- Press `E` to equip, and arm/disarm weapons, `LMB` to attack, and `RMB` to dodge.
- Press the `ESCAPE` key to open a pause/options menu to set game quality, windowed mode, and resolution.
  
# C++ Unreal Engine (5.3) Project - Slash

![image](https://github.com/user-attachments/assets/9a445fa2-0826-4c19-ac17-b84ec4bd8eb9)

![image](https://github.com/user-attachments/assets/43331cb2-a5ac-4c55-9a7d-ec1ada8bd5e4)


- Working on an Unreal Engine project for fun on the weekends to take a break from full-stack work and improve my C++.  Interests are in full-stack development, not necessarily game dev, but might be a fun hobby on the side.

- This project was started by following Stephen Ulibarri's Udemy course - Unreal Engine 5 C++ The Ultimate Game Developer Course.  I completed all lectures (53 hours of video) which likely took me about 100+ hours https://www.udemy.com/certificate/UC-3fcc4637-66f1-4b14-8c67-3b7dcce3fa06/, and now plan to use the levels created from the course as a test bed for futher work in Unreal Engine.

# Progress - From Beginning to Present

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

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/b9bab661-667a-4a2b-a9ca-7292e68dab80)

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/7f320ca8-1af6-4e7b-8566-ad993e0c3a12)

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/d027736f-dd63-4ba5-a43e-02fe6c35fc11)

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/6829ddf3-9a6c-4994-96a9-18db5e39c0f7)

<br />

![test_cropped](https://github.com/Mike11199/unreal-project-slash/assets/91037796/5ef8b2dd-7c71-4610-bf32-ec01e0d7cd79)

<br />

* Added blood particle effects with the Cascade particle system

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/523ae020-6e42-441b-b8d2-9ec5d21025cd)

<br />

* Added Voronoi uniform fracturing to an existing mesh ( a clay pot ) so it can break on hit with a weapon.  There are multiple levels of breakage/layers or Voronoi sites, so a mesh could break progressively at different levels of damage.

  <br />

  ![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/40e67497-c4e7-4661-8acd-de9dd34a70cc)

  <br />

* Then, added C++ code and blueprint nodes to create a physics field (external strain/ linear strain) which is created at the weapon's hit location, to apply a force to this destructible.  Now a weapon/sword strike will break the clay pot on hit as the destructible reacts to the physics force applied to it.

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/1aa91f93-e36e-45b5-b319-e5757337bb9c)

<br />



<br />

 ![physics_pot_break](https://github.com/Mike11199/unreal-project-slash/assets/91037796/5422664e-3432-4413-87ef-59e7313f7f16)


 <br />
  
* Added treasure with red glowing ember particles swirling around it in a vortex, using the Niagara particle system.  The treasure spawns randomly from a breakable, from simply indexing into a treasure item array with a random integer.  Also added these particles to the weapon's parent C++ class.  

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/238af4a2-a379-4d6d-8810-d67625c5a7f6)

<br />

*Added death animations for enemies by adding various C++ classes and Blueprints.  A UAttributeComponent records the enemies health and alive state, and has a setter for damage.  The health bar widget's visibility is determined from C++, and disappears if the player character moves a certain distance from the enemy (from calcuating the vector distances between the enemy and player in the tick function).

<br />

<img src="https://github.com/Mike11199/unreal-project-slash/assets/91037796/57e0dd59-481b-4539-aa48-6b18245fabd4" alt="Image Alt Text" width="120%" >

<br />
<br />

<img src="https://github.com/Mike11199/unreal-project-slash/assets/91037796/0c2553fe-bbcb-492d-919e-567445ca5e53" alt="Image Alt Text" width="80%" >

<br />
<br />

![DeathAnimations3](https://github.com/Mike11199/unreal-project-slash/assets/91037796/e9e6fd72-c176-46b2-b9cd-0069c1d7aeed)

# Enemy Artificial Intelligence

<br />

* Added a Nav Mesh Bounds to define the area where the enemy AI can move around.  A navigation mesh, or navmesh, is an abstract data structure used in artificial intelligence applications to aid agents in pathfinding through complicated spaces.  Pathfinding for the AI is then done with a graph search algorithm (under the hood in the engine).

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/7343c785-97b7-4319-a762-cb0426a2990d)

<br />

* Added an AAIController class, and logic in C++ to instruct enemies to move to random patrol points on the map.
 
<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/f99d24a2-e657-456a-a1de-489cd84c0657)

<br />

![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/4af6b73e-8a58-4e94-9e5e-074b90750e65)

<br />

* Added a pawn sensing component, so that an enemy can run towards a player character if they enter the enemy's field of vision.

<br />

  ![image](https://github.com/Mike11199/unreal-project-slash/assets/91037796/f5b1a2bd-4e88-476b-a143-502785c2baa4)

* Implemented a BaseCharacter class which enemy and slash character inherits from.  The child classes can override functions as needed.  Added in new animations for the enemy class, states such as attacking/engaged, and attack timers.  This prevents sliding while attacking and other bad movement.

![image](https://github.com/user-attachments/assets/97630967-c73e-4a97-8a6c-ad3fb22e847c)


* Implemented motion warping.  This allows an enemy's attacks to skew towards the player character's rotation and location  The enemy will turn towards the player during an attack and is more difficult to dodge.  This requires vector math to calculate an offset location within C++, used in a Blueprint Callable function on the attack montage's animation graph.  The function plays in response to anim notify events.

![image](https://github.com/user-attachments/assets/388c2840-3cce-4d9d-bdb9-e93c2a547f42)

![image](https://github.com/user-attachments/assets/55d45f93-cfe6-4aaa-85d3-2d5e10cec1e3)

![image](https://github.com/user-attachments/assets/62f4b1be-b2f9-4ab1-9815-633976aec15c)



# Set HUD 

* Implemented a game HUD showing health/stamina, and gold/soul count using C++ classes.  These inherit from the UUserWidget amd UWidgetComponent Unreal classes.  Added public functions to allow setting the HUD variables directly from C++.

<br />

![image](https://github.com/user-attachments/assets/16617e92-30f3-46e3-a43d-deb71e633afe)

<br />

![image](https://github.com/user-attachments/assets/7f22db5a-a64b-44c1-b696-b91ec377c5a7)

<br />

![image](https://github.com/user-attachments/assets/110f8874-f92a-453b-bc23-f65158437680)


# Souls Particle System

- Modified the material of a planar mesh - associated with a Niagra particle system to create a warping cloud effect - for enemy soul drops.

![image](https://github.com/user-attachments/assets/c3713827-20b7-4510-86b3-eb3e3ef30301)

![image](https://github.com/user-attachments/assets/10277be1-40dd-46f8-ba2a-c9d8c43b1c37)

![image](https://github.com/user-attachments/assets/9968cc9c-4055-4dc4-b857-094b54412852)


# New Enemies

- Added a new `Raptor` enemy per the tutorial.  This was made easier by creating an animation template blueprint that enemy blueprint's can inherit from (parent to).  

  ![image](https://github.com/user-attachments/assets/26754398-f49b-4510-a09b-5874dd43dc0a)

= Then added a new `Insect` type enemy following the same steps.

![image](https://github.com/user-attachments/assets/918400da-8074-4fee-a743-5cc5bd46392d)

- Implemented ragdoll physics on the insect enemy by exposing the C++ `Die()` function as a Blueprint Callable event.  Then in Blueprint, set the mesh to simulate physics.  This is made possible by also adding a physics field to the insect's skeletal mesh.

  ![image](https://github.com/user-attachments/assets/79a90d71-5291-42e9-bf9b-f733aa647172)

  ![image](https://github.com/user-attachments/assets/a12f4682-5e36-4ae0-b921-98ca4dd5e1f1)

 
