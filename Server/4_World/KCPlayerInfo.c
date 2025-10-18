#ifndef KUBC_PLAYER_INFO
/// @brief Класс отправки сообщений игрокам
class KCPlayerInfo
{
    /// @brief Отправить сообщение всем игрокам
    /// @param message текст сообщения игрокам
    void SendMessage(string message)
    {
		KCInfo.Log("[ВСЕМ] " + message);
        array<Man> players = new array<Man>; 
		GetGame().GetPlayers(players);
        Param1<string> paramMessage = new Param1<string>(message);
		//Поочередно перебираем каждого игрока
		for (int i = 0; i < players.Count(); i++ ) 
		{
			//Берем конкретного игрока сервера
			PlayerBase player = PlayerBase.Cast(players.Get(i));
			if((player)&&(player.GetIdentity()))
			{
				GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, paramMessage, false, player.GetIdentity());
			}
		}
    }
}
#define KUBC_PLAYER_INFO
#endif