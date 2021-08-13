//
// Created by Hugo Zheng on 2021-08-12.
//

#ifndef COMP371_PROJECT_SRC_CUBE_H_
#define COMP371_PROJECT_SRC_CUBE_H_

#include "Material.h"
#include <glm/gtc/quaternion.hpp>

class Cube {
 private:
  const long vertexArrayLength = 288;

  float *vertices;
  unsigned int vao = 0;

  Material material;
  glm::vec3 position{glm::vec3(0.0f)};
  glm::quat quaternion{glm::quat(glm::vec3(0.0f))};
  float scale = 1.0f;
  glm::mat4 modelMatrix{glm::mat4(1.0f)};

  void updateModelMatrix();

 public:
  /**
   * Create a cube with provided material and with unit cube vertices
   * @param material
   */
  explicit Cube(const Material &material);

  /**
   * Create a cube with provided material and provided vertices
   * @param material
   * @param vertices
   */
  Cube(Material &material, float *vertices);

  glm::mat4 getModelMatrix();

  void setPosition(glm::vec3 newPosition);

  /**
   * Draw this cube
   * @param shader
   * @param shaderHasMaterial whether the shader requires a material
   * @param isGlowingOn whether glowing effect is on
   */
  void draw(Shader &shader, bool shaderHasMaterial, bool isGlowingOn);

  void draw(Shader &shader, bool shaderHasMaterial);
};

#endif //COMP371_PROJECT_SRC_CUBE_H_