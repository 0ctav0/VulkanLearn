#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>

constexpr auto WIDTH = 800;
constexpr auto HEIGHT = 600;

class HelloTriangleApplication {
public:
   void run() {
      initWindow();
      initVulkan();
      mainLoop();
      cleanup();
   }
private:
   GLFWwindow* window;

   void initWindow() {
      glfwInit();
      glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
      window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
   }

   void initVulkan() {

   }

   void mainLoop() {
      while (!glfwWindowShouldClose(window)) {
         glfwPollEvents();
      }
   }

   void cleanup() {
      glfwDestroyWindow(window);
      glfwTerminate();
   }
};

int main() {
   HelloTriangleApplication app;

   try {
      app.run();
   }
   catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;

   uint32_t extensionCount = 0;
   vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

   std::cout << extensionCount << " extenstions supported\n";

   glm::mat4 matrix;
   glm::vec4 vec;
   auto test = matrix * vec;
}