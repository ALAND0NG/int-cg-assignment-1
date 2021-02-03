#include "AssignmentScene.h"
#include <AssetLoader.h>
void AssignmentScene::InitScene()
{
	m_sceneReg = new entt::registry;
	ECS::AttachRegistry(m_sceneReg);

	ECS::Create(0); 
	ECS::Add<Transform>(0);
	ECS::Add<PhysicsBody>(0);
	ECS::Add<Camera>(0);
	ECS::Add<Player>(0);
	ECS::Get<Camera>(0).ResizeWindow(1920, 1080);
	ECS::Get<PhysicsBody>(0).AddBody(100, btVector3(0, 4, 0), btVector3(1, 2, 1), 3.0f);
	ECS::Get<PhysicsBody>(0).m_Entity = 0;
	ECS::Get<Player>(0).SetMovementSpeed(10.f);
	ECS::Get<Player>(0).SetHp(5);
	

	ECS::Create(1);
	ECS::Add<Mesh>(1);
	ECS::Add<Material>(1);
	ECS::Add<Transform>(1);
	ECS::Add<PhysicsBody>(1);
	ECS::Get<Mesh>(1).LoadOBJ("models/cube.obj", glm::vec4(1, 1, 1, 1));
	ECS::Get<Transform>(1).SetScale(glm::vec3(1.f, 1.f, 1.f));
	ECS::Get<Material>(1).LoadDiffuseFromFile("images/doge.png");
	ECS::Get<Material>(1).LoadSpecularFromFile("images/doge.png");
	ECS::Get<Material>(1).SetAll(1.f);
	ECS::Get<PhysicsBody>(1).AddBody(0.f, btVector3(10, 2, 10), btVector3(2, 2, 2));
	ECS::Get<PhysicsBody>(1).m_Entity = 1;
	


	ECS::Create(2);
	ECS::Add<Mesh>(2);
	ECS::Add<Material>(2);
	ECS::Add<Transform>(2);
	ECS::Add<PhysicsBody>(2);
	ECS::Get<Mesh>(2).LoadOBJ("models/plane.obj", glm::vec4(1, 1, 1, 1));
	ECS::Get<Transform>(2).SetScale(glm::vec3(10000.f, 1.f, 10000.f));
	ECS::Get<Material>(2).LoadDiffuseFromFile("images/missing.png");
	ECS::Get<Material>(2).LoadSpecularFromFile("images/missing.png");
	ECS::Get<Material>(2).SetAll(1.f);
	ECS::Get<PhysicsBody>(2).AddBody(0.f, btVector3(0, 0, 0), btVector3(10000, 0, 100000));
	ECS::Get<PhysicsBody>(2).m_Entity = 2;


	ECS::Create(3);
	ECS::Add<Mesh>(3);
	ECS::Add<Material>(3);
	ECS::Add<Transform>(3);
	ECS::Add<PhysicsBody>(3);
	ECS::Get<Mesh>(3).LoadOBJ("models/triangle.obj", glm::vec4(1, 1, 1, 1));
	ECS::Get<Transform>(3).SetScale(glm::vec3(1.f, 1.f, 1.f));
	ECS::Get<Material>(3).LoadDiffuseFromFile("images/obama.png");
	ECS::Get<Material>(3).LoadSpecularFromFile("images/obama.png");
	ECS::Get<Material>(3).SetAll(1.f);
	ECS::Get<PhysicsBody>(3).AddBody(0.f, btVector3(15, 2, 10), btVector3(2, 2, 2));
	ECS::Get<PhysicsBody>(3).m_Entity = 3;

}

void AssignmentScene::Update()
{
	ECS::Get<Transform>(3).SetRotation(glm::vec3(0.f, 1.f, 0.f),0.2);
}
