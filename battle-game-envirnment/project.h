#pragma once


// can be found in the axis.cpp file
void drawGrid();
void drawAxis();
void ground();

// can be found in plane.cpp
void plane();
void groupPlanes();

//can be found in watch_Tower.cpp
void watchTower();

// can be found in the terrain.cpp
void terrain();

//can be found in arterygun.cpp
void arteryGun();




//can be found in arteryshell.cpp
void artilleryShell();
void artilleryEmptyShell();
void artilleryAmmoCrate();


//can be found in soilpillow.cpp
void soilPillow();

//can be found  in buildings.cpp
void brokenHouse();
void woodHouse();
void largeBuilding();
void singleWindow();


//can be found in tree.cpp
void maketree(float height, float Base, float r, float g, float b);





//can be found in lampTower.cpp
void lampTower(int i);


//can be found in components.cpp
void cylinder(float br, float tr, float h, int slices);
void cylinderWithCap(float br, float tr, float h, int slices);
void halfCylinderWithCaps(float br, float tr, float h, int slices);
void halfCylinderWithoutCaps(float br, float tr, float h, int slices);