#include "db_cache/db_cache.h"



DBCache::rec_state DBCache::get_record(const std::string& key, std::string& result)
{
	bool expected = false, desired = true;
	while(bool lock_succeeded = locked_.at(key).compare_exchange_strong(expected, desired))
		;



	// TODO: unlock
}




std::string DBCache::Read(const std::string& key)
{
//	Если поток запросил запись, которая занята другим потоком, то он должен ждать записи некоторое время, по истечению которого выкинуть исключение.




//- Если поток запросил запись, которой нет в кэше, то кэш должен подгрузить её из базы.
//
//- Если поток запросил запись, которой нет в базе данных, то кэш должен создать пустую запись в базе с запрашиваемым ключом.
}

void DBCache::Write(const std::string& key, const std::string& data)
{

}