#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center
	vec3 camera_position(1, 1, 0);
	vec3 camera_look(0, 0, 0);
	App->camera->Move(camera_position);
	App->camera->LookAt(camera_look);
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference
	
	Plane plane(0,1,0,0);
	plane.axis = true;
	plane.Render();
	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe

	Sphere sphere;
	sphere.radius = 0.5f;
	sphere.SetPos(0.0f, 0.0f, 0.0f);
	sphere.Render();

	Cube cube;
	cube.size = 3;
	cube.SetPos(2.5f, 2.5f, 0.0f);
	cube.wire = true;
	cube.Render();

	Cylinder cylinder;
	cylinder.radius = 0.5f;
	cylinder.SetPos(-2.5f, 2.5f, 0.0f);
	cylinder.wire = true;
	cylinder.Render();

	

	return UPDATE_CONTINUE;
}

