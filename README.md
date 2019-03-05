# Project overview

This project presents a simple implementation of [Conway's Game of Life](https://bitstorm.org/gameoflife/). It serves me for teaching purposes.

[Conan](https://conan.io/) is used to get the required dependencies (just [{fmt}](https://github.com/fmtlib/fmt) for now) and [CMake](https://cmake.org/) to configure and build the project.

# To build the project
From a terminal, run:
```shell
git clone https://github.com/BenjaminNavarro/game-of-life.git
cd game-of-life/build
conan install ..
cmake ..
cmake --build .
```

# To run the project
From a terminal, run:
```shell
cd game-of-life/build
./bin/game-of-life
```

Example output:
```
=======   Generation #11   =======


                    ***                 
                   *   *                
                   *   *                
                 **     **              
                *    *    *             
                *   * *   *             
                *    *    *             
                 **     **              
                   *   *                
                   *   *                
                    ***                 


```
```
=======   Generation #12   =======


                     *                  
                    ***                 
                   * * *                
                   *   *                
                 **     **              
                *    *    *             
               ***  * *  ***            
                *    *    *             
                 **     **              
                   *   *                
                   * * *                
                    ***                 
                     *                  


```
```
=======   Generation #13   =======




                    ***                 

                   * * *                
                   ** **                
                 **     **              
               *  *  *  *  *            
               * *  * *  * *            
               *  *  *  *  *            
                 **     **              
                   ** **                
                   * * *                

                    ***                 




```
```
=======   Generation #14   =======



                     *                  
                     *                  

                   * * *                
                   *****                
                 ** *** **              
                  ** * **               
              ** **** **** **           
                  ** * **               
                 ** *** **              
                   *****                
                   * * *                

                     *                  
                     *                  



```
