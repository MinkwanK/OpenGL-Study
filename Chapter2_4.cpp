#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
    //glfw 초기화
    glfwInit();
    
    //첫번째 옵션은 무슨 기능 옵션 쓸 것인지, 두번째 인수는 버전
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    //Immediate Mode(easy)나 Core_Profile(more flexible,hard) 둘 중 뭘 쓸지
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    //첫 NULL은 전체화면 할지 안할지, 안에 내용을 다른 것과 공유할거냐
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //Context에 window를 main context로 쓰겠다.
    glfwMakeContextCurrent(window);

    //GLAD초기화 , glfwGetProcAddress: os 별로 함수 포인터의 주소를 반환. 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //렌더링 할 화면 사이즈가 바뀔때마다 호출된다.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 

    while (!glfwWindowShouldClose(window))
    {
        //window를 통해 입력을 받겠다.
        processInput(window);

     

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //컬러 버퍼가 두개있다. 하나는 화면에 나타내고 하나는 뒤에서 수정.
        glfwSwapBuffers(window);

        //어떤 이벤트가 실행 됐는지 확인한다.
        glfwPollEvents();

    }

    //할당된 자원 제거
    glfwTerminate();
    return 0;
}

//렌더링 할 사이즈, 화면 크기가 바뀔때마다 호출된다.
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //처음 두번째 매개변수는 왼쪽 모서리에서의 창 위치
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
