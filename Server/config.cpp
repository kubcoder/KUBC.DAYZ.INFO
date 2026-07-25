class CfgPatches
{
	class KUBCinfo
	{
		units[]= {};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]= {
			"KUBCconsole"
		};
	};
};
class CfgMods 
{
	class KUBCinfo
	{
		name = "KUBC.DAYZ.INFO";
		author = "kubcoder";
		version = 1.2;
		type = "mod";
		class defs 
		{
			class worldScriptModule {
				value = "";
				files[] = {"KUBC.DAYZ.INFO\4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]={"KUBC.DAYZ.INFO\5_Mission"};
			};
		}; 
	};
};