#pragma once


// can be found in the axis.cpp file
void drawGrid();
// can be found in the axis.cpp file
void drawAxis();
// can be found in the axis.cpp file
void ground();



// can be found in plane.cpp
void plane();
// can be found in plane.cpp
void groupPlanes();
// can be found in plane.cpp
void brokenPlane();


//can be found in watchTower.cpp
void watchTower(float angle);

//can be found in arterygun.cpp
void arteryGun(float angle);
//can be found in arterygun.cpp
void groundMiniGunBase(float angle);



//can be found in arteryshell.cpp
void artilleryShell();
//can be found in arteryshell.cpp
void artilleryEmptyShell();
//can be found in arteryshell.cpp
void artilleryAmmoCrate();


//can be found in soilpillow.cpp
void soilPillow();



//can be found  in buildings.cpp
void brokenHouse();
//can be found  in buildings.cpp
void woodHouse();
//can be found  in buildings.cpp
void largeBuilding();
//can be found  in buildings.cpp
void singleWindow();


//can be found in tree.cpp
void maketree(float height, float Base, float r, float g, float b);


//can be found in lampTower.cpp
void lampTower(int i, int leaks);


//can be found in components.cpp
void cylinder(float br, float tr, float h, int slices);
//can be found in components.cpp
void cylinderWithCap(float br, float tr, float h, int slices);
//can be found in components.cpp
void halfCylinderWithCaps(float br, float tr, float h, int slices);
//can be found in components.cpp
void halfCylinderWithoutCaps(float br, float tr, float h, int slices);


//can be found in machineGun.cpp
void machineGun(float angle, int laserVisible);
//can be found in machineGun.cpp
void miniGun(int laserVisible);

//can be found in fence.cpp
void drawFenceRow(int number);


//can be found in boxes.cpp
void containerBox(int open, float r, float g, float b);
//can be found in boxes.cpp
void woodenBox();

//can be found in radarSet.cpp
void radarMachine(float angle);

//can be found in helicopter.cpp
void helicopter(float angle);
//can be found in helicopter.cpp
void helipad();

//can be found in armorTank.cpp
void armorTank(float tankWheel, float tankTurrent);