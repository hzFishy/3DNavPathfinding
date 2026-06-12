// Copyright Dominik Trautman. Published in 2022. All Rights Reserved.

using UnrealBuildTool;

public class CPathfinding : ModuleRules
{
	public CPathfinding(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
		});
			
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"CoreUObject", "Engine",
			"Slate", "SlateCore",
		});
	}
}
