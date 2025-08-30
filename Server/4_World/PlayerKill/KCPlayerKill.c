class KCPlayerKill
{
    private ref KCPlayerKillConfig config;

    private ref KCPlayerInfo playerInfoSystem;

    void KCPlayerKill(KCPlayerInfo playerInfo, KCPlayerKillConfig playerKillConfig)
    {
        config = playerKillConfig;
        playerInfoSystem = playerInfo;
    }

    bool SendMessage(PlayerBase player, Object killer)
    {
        KCInfo.Log("Обработка информации об убийстве другим игроком");
        if (IsHandKill(player, killer))
        {
            return true;
        }
        return WeaponKill(player, killer);
    }

    private bool IsHandKill(PlayerBase player, Object killer)
    {
        PlayerBase playerSource = PlayerBase.Cast(killer);
        if (playerSource)
        {
            if (config.Enable)
            {
                string message = string.Format(config.MessageHand, player.GetIdentity().GetName(), playerSource.GetIdentity().GetName());
                playerInfoSystem.SendMessage(message);
            }
            return true;
        }
        return false;
    }

    private bool WeaponKill(PlayerBase player, Object killer)
    {
        PlayerBase playerSource = PlayerBase.Cast(EntityAI.Cast(killer).GetHierarchyParent());
        if (playerSource)
        {
            if (IsMeleeWeapon(player, killer, playerSource))
            {
                return true;
            }
            return IsWeapon(player, killer, playerSource);
        }
        else
            return false;
    }

    private bool IsMeleeWeapon(PlayerBase player, Object killer, PlayerBase playerSource)
    {
        if (killer.IsMeleeWeapon())
        {
            if (config.Enable)
            {
                string message = string.Format(config.Message, player.GetIdentity().GetName(), playerSource.GetIdentity().GetName(), killer.GetDisplayName());
                playerInfoSystem.SendMessage(message);
            }
            return true;
        }
        return false;
    }

    private bool IsWeapon(PlayerBase player, Object killer, PlayerBase playerSource)
    {
        if (killer.IsWeapon())
        {
            if (config.Enable)
            {
                float distance = vector.Distance( player.GetPosition(), playerSource.GetPosition() );
                string message = string.Format(config.MessageDistance, player.GetIdentity().GetName(), playerSource.GetIdentity().GetName(), killer.GetDisplayName(), distance);
                playerInfoSystem.SendMessage(message);
            }
            return true;
        }
        return false;
    }
}