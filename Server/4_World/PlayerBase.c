modded class PlayerBase
{
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		MissionBaseWorld mission = MissionBaseWorld.Cast(GetGame().GetMission());
		if (mission)
		{
			if (CommitedSuicide())
			{
				if (mission.SuicideInfoSystem)
				{
					mission.SuicideInfoSystem.SendMessage(this);
				}
			}
			else
			{
				if (mission.PlayerDeadInfoSystem)
				{
					mission.PlayerDeadInfoSystem.SendMessage(this, killer);
				}
			}
			
		}
	}

}