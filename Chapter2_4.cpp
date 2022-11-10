#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
    //glfw �ʱ�ȭ
    glfwInit();
    
    //ù��° �ɼ��� ���� ��� �ɼ� �� ������, �ι�° �μ��� ����
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    //Immediate Mode(easy)�� Core_Profile(more flexible,hard) �� �� �� ����
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    //ù NULL�� ��üȭ�� ���� ������, �ȿ� ������ �ٸ� �Ͱ� �����Ұų�
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //Context�� window�� main context�� ���ڴ�.
    glfwMakeContextCurrent(window);

    //GLAD�ʱ�ȭ , glfwGetProcAddress: os ���� �Լ� �������� �ּҸ� ��ȯ. 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //������ �� ȭ�� ����� �ٲ𶧸��� ȣ��ȴ�.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 

    while (!glfwWindowShouldClose(window))
    {
        //window�� ���� �Է��� �ްڴ�.
        processInput(window);

     

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //�÷� ���۰� �ΰ��ִ�. �ϳ��� ȭ�鿡 ��Ÿ���� �ϳ��� �ڿ��� ����.
        glfwSwapBuffers(window);

        //� �̺�Ʈ�� ���� �ƴ��� Ȯ���Ѵ�.
        glfwPollEvents();

    }

    //�Ҵ�� �ڿ� ����
    glfwTerminate();
    return 0;
}

//������ �� ������, ȭ�� ũ�Ⱑ �ٲ𶧸��� ȣ��ȴ�.
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //ó�� �ι�° �Ű������� ���� �𼭸������� â ��ġ
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
/*
void render(GLFWwindow* window);

int main()
{
    // glfw �ʱ�ȭ
    glfwInit();

    // window ����� (width, height, title, monitor, share)
    GLFWwindow* window = glfwCreateWindow(640, 480, "Inyong", 0, 0);

    // context�� �׸��� ���� ������ ��� ����
    // window�� �ΰ��̸� context�� �ΰ��ϼ��� ����
    // �׷��� � context�� �׸��� ������� ��
    glfwMakeContextCurrent(window);

    // ����ڰ� window â�� ���� ������
    while (!glfwWindowShouldClose(window)) {
        // window �׷��ֱ�
        render(window);

        // ���콺 �����̴� ��. �̷��͵� ���ͼ� �ʿ��� window���� �����ֱ�
        glfwPollEvents();
    }

    // window�� ������ ��� ������
    glfwDestroyWindow(window);
    glfwTerminate();
}

void render(GLFWwindow* window) { }

*/