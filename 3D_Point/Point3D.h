#ifndef D28F6842_CBE6_481D_9DE3_B76CB9EEFE8B
#define D28F6842_CBE6_481D_9DE3_B76CB9EEFE8B

class Point3D{
private:

    float x;
    float y;
    float z;

public:
    /**
     * @brief Construct a new Point 3D object, setting the points as x = xx,
     * y = yy and z =zz
     * @param xx 
     * @param yy 
     * @param zz 
     */
    Point3D(float xx, float yy, float zz);

    /**
     * @brief Destroy the Point 3 D object
     */
    ~Point3D();
    
    /**
     * @brief Return the coordinate
     * 
     * @return the x coordinate
     */
    float getX();

    /**
     * @brief Return the coordinate
     * 
     * @return the y coordinate
     */
    float getY();

    /**
     * @brief Return the coordinate (float)
     * 
     * @return the z coordinate
     */
    float getZ();

    /**
     * @brief Calculate the distance b2w the point that called the function and the 
     * point that is in the parameter
     * 
     * @param Point3D p2 
     * @return distance b2w the points
     */
    float distance(Point3D p2);

    /**
     * @brief setter to the val that's gonna be the x coordinate
     * 
     * @param val 
     */
    void setX(float val);

    /**
     * @brief setter to the val that's gonna be the y coordinate

     * 
     * @param val 
     */
    void setY(float val);

    /**
     * @brief setter to the val that's gonna be the z coordinate
     * 
     * @param val 
     */
    void setZ(float val);

    /**
     * @brief Check if the 3 points create a triangle
     * 
     * @param Point3D p2 
     * @param Point3D p3 
     * @return true 
     * @return false 
     */
    bool isTriangle(Point3D p2, Point3D p3);
};

#endif /* D28F6842_CBE6_481D_9DE3_B76CB9EEFE8B */
/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/