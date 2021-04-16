# Test Plan:

## High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |Check if Menu Screen is displayed |  No input | Menu is displayed properly|Obtained the required results|Requirement based |
|  H_02       |Check if grid works|No input|Prints grid|Obtained the required results|Requirement based|
|  H_03       |Check if coordinate input is working from user|Coordinates(x,y)|Grid responds to input|Obtained the required results|Scenario based|
|  H_04       |Check if dev mode works|Input argument "dev"| Grid updates accordingly |Obtained the required results|Requirement based |
|  H_05       |Check if user can retake game or quit|Input (y/n)|Restart Game or quit accordingly |Scenario based |
## Low level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       | Check collision of ship with boundary (grid)| Few ships within boundary and others outside boundary|Collision if ship is out of bounds|Obtained the required results for all the operations|Boundary based|
|  L_02       |Check collision of ship with another ship|Few ships which are colliding and others which are not|Collision if ship hits another ship|Obtained the required results for all the operations|Boundary based|
|  L_03       |Check collision of ships with boundary and other ships|Few ships which are colliding, few out of bounds and few proper ships|Collision if ship hits boundary or another ship|Obtained the required results for all the operations|Integration test|
|  L_04       |Check if ship coordinates function is returning proper value|Ship as input|Returns expected coordiantes|Obtained the required results for all the operations|Requirement based|
|  L_05       |Check if given input coordinate is hit or miss|Input is coordinates from user|Return true if the coordinates hit the target|Obtained the required results for all the operations|Requirement based|
|  L_06       |Check if ship is genrating properly with no collision|Pointer to ship|Check if returned ships have no collision |Obtained the required results for all the operations|Integraion based|
|  L_07       |Return number of ships all hit|Array of ships|Number of ships all hit|Obtained the required results for all the operations|Requirement based|
|  L_08       |Check if input coordinates are valid|Input coordiates from user|Return 1 if coordinate is not out of bounds and is not already used|Obtained the required results for all the operations|Boundary based|