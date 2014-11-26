#include "OpenGL_main.h"

#define precision_step 0.1f
#define sphere_radius 5.0f
#define start_point_x 0.0f
#define start_point_y 0.0f
#define start_point_z 0.0f

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
	_fgetchar();
}

void generateSphereModel(std::vector<GLfloat>* vertices, std::vector<unsigned int>* indices)
{
	//const GLfloat pi = glm::pi<GLfloat>();
	//const GLfloat pi2 = glm::two_over_pi<GLfloat>();
	//int ind = 0;
	//for(GLfloat i = 0.0f; i < pi2; i += precision_step)
	//{
	//	numOfVertsInMeridian = 0;
	//	for(GLfloat j = 0.0f; j < pi; j += precision_step)
	//	{
	//		GLfloat valX = start_point_x + sphere_radius * glm::sin(j) * glm::cos(i);
	//		GLfloat valY = start_point_y + sphere_radius * glm::sin(j) * glm::sin(i);
	//		GLfloat valZ = start_point_z + sphere_radius * glm::cos(j);
	//		vertex_buffer_data[ind] = valX;
	//		vertex_buffer_data[ind + 1] = valY;
	//		vertex_buffer_data[ind + 2] = valZ;
	//		ind += 3;
	//		numOfVertsInMeridian++;
	//	}		
	//	numMeridians++;
	//}
	//count = ind;

	const GLfloat pi = glm::pi<GLfloat>();
	const GLfloat pi2 = glm::two_over_pi<GLfloat>();
	int nCirclePointCount = 360;
	float angleStep = 2.0f * (float)pi / (float)nCirclePointCount;
	float angle = 0.0f;

	for(int i = 0; i < nCirclePointCount; i++)
	{
		float cosa = cos(angle) * 5.0f ;
		float sina = sin(angle) * 5.0f;
		// Отрисовка в плоскости X0Y
		//vertices->push_back(cosa);
		//vertices->push_back(sina);
		//vertices->push_back(0.0f);

		// Отрисовка в плоскости Z0X
		vertices->push_back(sina);
		vertices->push_back(0.0f);
		vertices->push_back(cosa);

		angle += angleStep;
	}

	for(int i = 0; i < nCirclePointCount; i++)
	{
		int triangleIndex = i * 3;
		indices->push_back(i);
		indices->push_back((i + 1) % nCirclePointCount);
		indices->push_back(nCirclePointCount);
	}
}

struct Point
{
	GLfloat x;
	GLfloat y;
	Point(GLfloat _x, GLfloat _y)
	{
		x = _x;
		y = _y;
	}
};

void generateSquareModel(std::vector<GLfloat>* vertices, std::vector<unsigned int>* indices, int numOfPointsW, int numOfPointsH, Point leftBottom, Point rightTop, std::vector<GLfloat>* uv)
{
	GLfloat absX = glm::abs(leftBottom.x - rightTop.x);
	GLfloat absY = glm::abs(rightTop.y - leftBottom.y);

	GLfloat stepX = glm::abs((leftBottom.x - rightTop.x) / numOfPointsW);
	GLfloat stepY = glm::abs((rightTop.y - leftBottom.y) / numOfPointsH);

	for(int i = 0; i < numOfPointsH + 1; i++)
	{
		for(int j = 0; j < numOfPointsW + 1; j++)
		{
			// Отрисовка в плоскости X0Y
			//vertices->push_back(leftBottom.x + j * stepX);
			//vertices->push_back(leftBottom.y + i * stepY);
			//vertices->push_back(0.0f);

			// Отрисовка в плоскости Z0X
			vertices->push_back(leftBottom.x + j * stepX);
			vertices->push_back(0.0f);			
			vertices->push_back(leftBottom.y + i * stepY);



			uv->push_back(static_cast<GLfloat>(j) / numOfPointsW);
			uv->push_back(static_cast<GLfloat>(i) / numOfPointsH);

		}
	}


	int numOfLinesW = numOfPointsW + 1;
	int numOfLinesH = numOfPointsH + 1;
	for(int i = 0; i < numOfPointsH; i++)
	{
		for(int j = 0; j < numOfPointsW; j++)
		{
			indices->push_back(i * numOfPointsW + j);
			indices->push_back(i * numOfPointsW + j + 1);
			indices->push_back((i + 1) * numOfPointsW + j);

			indices->push_back((i + 1) * numOfPointsW + j);
			indices->push_back(i * numOfPointsW + j + 1);
			indices->push_back((i + 1) * numOfPointsW + j + 1);			
		}
	}

}

int main()
{
	// Инициализируем GLFW
	if(!glfwInit())
	{
		fprintf(stderr, "Ошибка при инициализации GLFW\n");
		return -1;
	}

	glfwSetErrorCallback(error_callback);

	//glfwWindowHint(GLFW_SAMPLES, 4); // 4x Сглаживание
	//glfwWindowHint(GLFW_VERSION_MAJOR, 1); // Мы хотим использовать OpenGL 3.3
	//glfwWindowHint(GLFW_VERSION_MINOR, 1);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Мы не хотим старый OpenGL

	// Открыть окно и создать в нем контекст OpenGL
	GLFWwindow* window; // (В сопроводительном исходном коде эта переменная является глобальной)
	window = glfwCreateWindow(1024, 768, "Landscape", NULL, NULL);
	if(window == NULL)
	{
		fprintf(stderr, "Невозможно открыть окно GLFW. Если у вас Intel GPU, то он не поддерживает версию 3.3. Попробуйте версию уроков для OpenGL 2.1.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	// Инициализируем GLEW
	glewExperimental = true; // Флаг необходим в Core-режиме OpenGL
	if(glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Невозможно инициализировать GLEW\n");
		return -1;
	}





	std::vector<GLfloat> vertices;
	std::vector<unsigned int> indices;
	std::vector<GLfloat> uv;

	int texWidth = 0;
	int texHeight = 0;
	GLuint Texture = loadBMP_custom("land1.bmp", texWidth, texHeight);
	generateSquareModel(&vertices, &indices, texWidth, texHeight, Point(-1.0f, -1.0f), Point(1.0f, 1.0f), &uv);


	// Это будет идентификатором нашего буфера вершин
	GLuint vertexbuffer;

	// Создадим 1 буфер и поместим в переменную vertexbuffer его идентификатор
	glGenBuffers(1, &vertexbuffer);

	// Сделаем только что созданный буфер текущим
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	// Передадим информацию о вершинах в OpenGL
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* vertices.size(), &vertices[0], GL_STATIC_DRAW);

	// Включим режим отслеживания нажатия клавиш, для проверки ниже
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);




	//!!!!!!!!

	// fill "indices" as needed

	// Generate a buffer for the indices
	GLuint elementbuffer;
	glGenBuffers(1, &elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);


	// Создать и откомпилировать нашу шейдерную программу
	GLuint programID = LoadShaders("test.vert", "test.frag");

	// Проекционная матрица : 45° поле обзора, 4:3 соотношение сторон, диапазон : 0.1 юнит <-> 100 юнитов
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	// Матрица камеры
	glm::mat4 View = glm::lookAt(
		glm::vec3(0, 8, 8), // Камера находится в мировых координатах (4,3,3)
		glm::vec3(0, 0, 0), // И направлена в начало координат
		glm::vec3(0, 1, 0)  // "Голова" находится сверху
		);
	// Матрица модели : единичная матрица (Модель находится в начале координат)
	glm::mat4 Model = glm::mat4(1.0f);  // Индивидуально для каждой модели

	// Итоговая матрица ModelViewProjection, которая является результатом перемножения наших трех матриц
	glm::mat4 MVP = Projection * View * Model;



	GLuint uvBuffer;
	glGenBuffers(1, &uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, uv.size() * sizeof(unsigned int), &uv[0], GL_STATIC_DRAW);
	

	


	GLfloat old_time = static_cast<GLfloat>(glfwGetTime());
	GLfloat current_time = static_cast<GLfloat>(old_time);






	BulletPhysics* physics = new BulletPhysics();
	physics->initObjects();

	btCollisionShape* groundShape = new btStaticPlaneShape(btVector3(0, 1, 0), 1);

	btCollisionShape* fallShape = new btSphereShape(1);
	

	btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0)));
	btRigidBody::btRigidBodyConstructionInfo
		groundRigidBodyCI(0, groundMotionState, groundShape, btVector3(0, 0, 0));
	groundRigidBodyCI.m_restitution = 1.0f;
	//groundRigidBodyCI.m_friction = 1.5f;
	btRigidBody* groundRigidBody = new btRigidBody(groundRigidBodyCI);
	physics->getDynamicsWorld()->addRigidBody(groundRigidBody);


	btRigidBody* fallRigidBody = physics->addFallingSphere();
	fallRigidBody->applyCentralImpulse(btVector3(5, 5, 5));


	//for(int i = 0; i < 300; i++)
	//{
	//	physics->getDynamicsWorld()->stepSimulation(1 / 60.f, 10);

	//	btTransform trans;
	//	fallRigidBody->getMotionState()->getWorldTransform(trans);

	//	fprintf(stdout, "sphere height: %f \n", trans.getOrigin().getY());
	//}

	float cubeSize = 1.0;
	glm::vec3 cubePos(0.0f, 0.5f, 0.0f);

	std::vector<GLfloat> vertices1;
	std::vector<unsigned int> indices1;

	vertices1.push_back(cubePos.x - cubeSize * 0.5f);
	vertices1.push_back(cubePos.y - cubeSize * 0.5f);
	vertices1.push_back(cubePos.z - cubeSize * 0.5f);

	vertices1.push_back(cubePos.x - cubeSize * 0.5f);
	vertices1.push_back(cubePos.y - cubeSize * 0.5f);
	vertices1.push_back(cubePos.z + cubeSize * 0.5f);

	vertices1.push_back(cubePos.x + cubeSize * 0.5f);
	vertices1.push_back(cubePos.y - cubeSize * 0.5f);
	vertices1.push_back(cubePos.z + cubeSize * 0.5f);

	vertices1.push_back(cubePos.x + cubeSize * 0.5f);
	vertices1.push_back(cubePos.y - cubeSize * 0.5f);
	vertices1.push_back(cubePos.z - cubeSize * 0.5f);




	vertices1.push_back(cubePos.x - cubeSize * 0.5f);
	vertices1.push_back(cubePos.y + cubeSize * 0.5f);
	vertices1.push_back(cubePos.z - cubeSize * 0.5f);

	vertices1.push_back(cubePos.x - cubeSize * 0.5f);
	vertices1.push_back(cubePos.y + cubeSize * 0.5f);
	vertices1.push_back(cubePos.z + cubeSize * 0.5f);

	vertices1.push_back(cubePos.x + cubeSize * 0.5f);
	vertices1.push_back(cubePos.y + cubeSize * 0.5f);
	vertices1.push_back(cubePos.z + cubeSize * 0.5f);

	vertices1.push_back(cubePos.x + cubeSize * 0.5f);
	vertices1.push_back(cubePos.y + cubeSize * 0.5f);
	vertices1.push_back(cubePos.z - cubeSize * 0.5f);

	indices1.push_back(0);
	indices1.push_back(2);
	indices1.push_back(1);

	indices1.push_back(0);
	indices1.push_back(2);
	indices1.push_back(3);
///////////
	indices1.push_back(4);
	indices1.push_back(5);
	indices1.push_back(6);

	indices1.push_back(4);
	indices1.push_back(6);
	indices1.push_back(7);
////////////
	indices1.push_back(1);
	indices1.push_back(6);
	indices1.push_back(5);

	indices1.push_back(1);
	indices1.push_back(2);
	indices1.push_back(6);
////////////
	indices1.push_back(2);
	indices1.push_back(3);
	indices1.push_back(6);

	indices1.push_back(3);
	indices1.push_back(7);
	indices1.push_back(6);
	////////////
	indices1.push_back(3);
	indices1.push_back(4);
	indices1.push_back(7);

	indices1.push_back(3);
	indices1.push_back(0);
	indices1.push_back(4);
	////////////
	indices1.push_back(0);
	indices1.push_back(5);
	indices1.push_back(4);

	indices1.push_back(1);
	indices1.push_back(5);
	indices1.push_back(0);
	////////////

	// Это будет идентификатором нашего буфера вершин
	auto vertBuffer = std::make_shared<AKVertexBuffer>();

	GLuint vertexbuffer1;

	// Создадим 1 буфер и поместим в переменную vertexbuffer его идентификатор
	//glGenBuffers(1, &vertexbuffer1);

	//// Сделаем только что созданный буфер текущим
	//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);

	//// Передадим информацию о вершинах в OpenGL
	//glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* vertices1.size(), &vertices1[0], GL_STATIC_DRAW);


	////!!!!!!!!

	//// fill "indices" as needed

	//// Generate a buffer for the indices
	//GLuint elementbuffer1;
	//glGenBuffers(1, &elementbuffer1);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer1);

	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices1.size() * sizeof(unsigned int), &indices1[0], GL_STATIC_DRAW);

	vertBuffer->init(&vertices1[0], vertices1.size(), &indices1[0], indices1.size(), false);

	// Создать и откомпилировать нашу шейдерную программу
	GLuint cubeProgramID = LoadShaders("cube.vert", "cube.frag");


	// Включить тест глубины
	glEnable(GL_DEPTH_TEST);
	// Фрагмент будет выводиться только в том, случае, если он находится ближе к камере, чем предыдущий
	glDepthFunc(GL_LESS);

	///////////CEGUI
	//OpenGLRenderer& myRenderer = OpenGLRenderer::bootstrapSystem();
	//CEGUI::System& system(System::getSingleton());
	//CEGUI::GUIContext* d_guiContext = &system.getDefaultGUIContext();
	//SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");
	//d_guiContext->getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");
	//WindowManager& winMgr = WindowManager::getSingleton();
	//CEGUI::DefaultWindow* d_root = (DefaultWindow*)winMgr.createWindow("TaharezLook/FrameWindow", "Root");
	//// load font and setup default if not loaded via scheme
	//Font& defaultFont = FontManager::getSingleton().createFromFile("DejaVuSans-12.font");
	//// Set default font for the gui context
	//d_guiContext->setDefaultFont(&defaultFont);
	//CEGUI::System::getSingleton().notifyDisplaySizeChanged(Sizef(1024, 768));
	//d_guiContext->setRootWindow(d_root);
	//FrameWindow* wnd = (FrameWindow*)winMgr.createWindow("TaharezLook/FrameWindow", "Demo Window");
	//d_root->addChild(wnd);
	//wnd->setPosition(UVector2(cegui_reldim(0.25f), cegui_reldim(0.25f)));
	//wnd->setSize(USize(cegui_reldim(0.5f), cegui_reldim(0.5f)));
	//wnd->setMaxSize(USize(cegui_reldim(1.0f), cegui_reldim(1.0f)));
	//wnd->setMinSize(USize(cegui_reldim(0.1f), cegui_reldim(0.1f)));
	//wnd->setText("Hello World!");
	///////////////END CEGUI

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	do
	{

		
		// Вычислить MVP-матрицу в зависимости от положения мыши и нажатых клавиш
		//computeMatricesFromInputs(window);
		//glm::mat4 ProjectionMatrix = getProjectionMatrix();
		//glm::mat4 ViewMatrix = getViewMatrix();
		//glm::mat4 ModelMatrix = glm::mat4(1.0);
		//glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;



		old_time = current_time;
		current_time = static_cast<GLfloat>(glfwGetTime());
		GLfloat delta_time = static_cast<GLfloat>(current_time - old_time);
		GLfloat FPS = static_cast<GLfloat>(1.0 / delta_time);
		//fprintf(stdout, "delta = %f \n", FPS);

		physics->getDynamicsWorld()->stepSimulation(delta_time);
		btTransform trans;
		fallRigidBody->getMotionState()->getWorldTransform(trans);
		btScalar posY = trans.getOrigin().getY();
		if(glm::abs(1.0f - posY) > 0.001f)
			fprintf(stdout, "sphere height: %f \n", posY);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);
		// Получить хэндл переменной в шейдере
		// Только один раз во время инициализации.
		GLuint MatrixID = glGetUniformLocation(programID, "MVP");
		// Передать наши трансформации в текущий шейдер
		// Для каждой модели, которую вы выводите MVP будет различным (как минимум часть M)
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
		
		// Указываем, что первым буфером атрибутов будут вершины
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // Атрибут 0. Подробнее об этом будет рассказано в части, посвященной шейдерам.
			3,                  // Размер
			GL_FLOAT,           // Тип
			GL_FALSE,           // Указывает, что значения не нормализованы
			0,                  // Шаг
			(void*)0            // Смещение массива в буфере
			);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			2,                                // size : U+V => 2
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
			);

		// Index buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

		// Draw the triangles !
		glDrawElements(
			GL_TRIANGLES,      // mode
			indices.size(),    // count
			GL_UNSIGNED_INT,   // type
			(void*)0           // element array buffer offset
			);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);






		glm::mat4 ModelMatCube = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, posY, 0.0f));
		glm::mat4 MVPCube = Projection * View * ModelMatCube;
		glUseProgram(cubeProgramID);
		GLuint cubeMatrixID = glGetUniformLocation(cubeProgramID, "MVP");
		glUniformMatrix4fv(cubeMatrixID, 1, GL_FALSE, &MVPCube[0][0]);

		

		//GLuint posYoffsetID = glGetUniformLocation(cubeProgramID, "posYoffset");
		//glUniform1f(posYoffsetID, posY);

		glEnableVertexAttribArray(2);
		vertBuffer->bindVertices();
		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			2,                  // Атрибут 0. Подробнее об этом будет рассказано в части, посвященной шейдерам.
			3,                  // Размер
			GL_FLOAT,           // Тип
			GL_FALSE,           // Указывает, что значения не нормализованы
			0,                  // Шаг
			(void*)0            // Смещение массива в буфере
			);

		// Index buffer
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer1);
		vertBuffer->bindIndices();

		// Draw the triangles !
		glDrawElements(
			GL_TRIANGLES,      // mode
			indices1.size(),    // count
			GL_UNSIGNED_INT,   // type
			(void*)0           // element array buffer offset
			);

		glDisableVertexAttribArray(2);




		glUseProgram(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//System::getSingleton().injectTimePulse(delta_time);
		//System::getSingleton().renderAllGUIContexts();

		// Сбрасываем буферы
		glfwSwapBuffers(window);
		glfwPollEvents();

		

	} // Проверяем нажатие клавиши Escape или закрытие окна
	while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	glfwWindowShouldClose(window) == 0);
	//delete[] g_vertex_buffer_data;

}
