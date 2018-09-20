#pragma once

#include <string>
#include <unordered_map>
#include <atomic>
#include <condition_variable>

#include "db_adapter/db_adapter.h"



class DBCache
{
public:
	DBCache(const std::string& dbname, const std::string& tblname, const std::string& datacolname)
	: dba_(dbname, tblname, datacolname)
	{}

	std::string Read(const std::string& key);
	void Write(const std::string& key, const std::string& data);

private:
	enum class rec_state {ready, waiting, loading, creating};

	rec_state get_record(const std::string& key, std::string& result);

private:
	std::unordered_map<std::string, std::atomic<bool>> locked_;
	std::unordered_map<std::string, std::string> table_;

	// TODO queues?

	DBAdapter dba_;
};