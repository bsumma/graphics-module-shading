//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/


#ifndef __OBJLOADER__
#define __OBJLOADER__

#include "common.h"

using namespace Angel;

class Mesh{
public:
  bool hasUV;
  std::vector < vec4 > vertices;
  std::vector < vec2 > uvs;
  std::vector < vec3 > normals;
  
  vec3 box_min;
  vec3 box_max;
  vec3 center;
  float scale;
  
  mat4 model_view;
  
  Mesh(const char * path, mat4 M=mat4())
    : box_min((std::numeric_limits< float >::max)(),
              (std::numeric_limits< float >::max)(),
              (std::numeric_limits< float >::max)() ),
    box_max(0,0,0),
    center(0,0,0),
    scale(1.0),
    model_view(M){ loadOBJ(path); }
  
  unsigned int getNumTri(){ return vertices.size()/3; }

  bool loadOBJ(const char * path);
  
  friend std::ostream& operator << ( std::ostream& os, const Mesh& v ) {
    os << "Vertices:\n";
    for(unsigned int i=0; i < v.vertices.size(); i++){
      os << "\t\t" << v.vertices[i] << "\n";
    }
    os << "Normals:\n";
    for(unsigned int i=0; i < v.normals.size(); i++){
      os << "\t\t" << v.normals[i] << "\n";
    }
 
    return os;
  }
  
};


#endif  //#ifndef __OBJLOADER__
