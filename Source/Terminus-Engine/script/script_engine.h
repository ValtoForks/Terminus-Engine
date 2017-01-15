#pragma once

#include <ECS/component_pool.h>
#include <types.h>
#include <sol.hpp>

namespace terminus
{
	using LuaObject	  = sol::table;
	using LuaFunction = sol::function;

	struct ScriptListener
	{
		LuaFunction _callback;
		LuaObject   _object;
	};

	class ScriptEngine
	{
	public:
		ScriptEngine();
		~ScriptEngine();
		void initialize();
		void shutdown();
		void execute_string(String _script);

	private:
		sol::state _lua_state;
	};
}