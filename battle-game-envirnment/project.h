#pragma once


// can be found in the axis.cpp file
void drawGrid();
void drawAxis();
void ground();

// can be found in plane.cpp
void plane();
void groupPlanes();
void brokenPlane();

//can be found in watch_Tower.cpp
void watchTower(float angle);

//can be found in arterygun.cpp
void arteryGun(float angle);
void groundMiniGunBase(float angle);



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
void lampTower(int i, int leaks);


//can be found in components.cpp
void cylinder(float br, float tr, float h, int slices);
void cylinderWithCap(float br, float tr, float h, int slices);
void halfCylinderWithCaps(float br, float tr, float h, int slices);
void halfCylinderWithoutCaps(float br, float tr, float h, int slices);


//can be found in machineGun.cpp
void machineGun(float angle);

//can be found in fence.cpp
void drawFenceRow(int number);


//can be found in boxes.cpp
void containerBox(int open, float r, float g, float b);