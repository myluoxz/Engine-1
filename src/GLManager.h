#ifndef GL_MANAGER_H
#define GL_MANAGER_H

#include <glm/glm.hpp>
#include <GL/glew.h>

#include <stack>

#include "Shader.h"
#include "SceneNode.h"
#include "Transform.h"

class GLManager
{
public:
  GLManager(int width, int height);
  ~GLManager(void);

  void renderScene(SceneNode *scene);
  void setViewProjection(const glm::mat4& viewProj);

private:
  void recursiveSceneRenderer(SceneNode *scene);
  void createShaders(void);

  Shader *shader1;

  glm::mat4 viewProj;

  std::stack<glm::mat4> transformStack;
};

#endif
