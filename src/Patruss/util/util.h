#pragma once

#include <iostream>
#include <string>
#include <SDL_error.h>

enum LogLevel
{
	llInfo, llWarn, llError
};

template<typename TF>
void log(std::ostream& stream, TF const& f)
{
	stream << f;
}

template<typename TF, typename ... TR>
void log(std::ostream& stream, TF const& f, TR const& ... rest)
{
	stream << f;
	log(stream, rest...);
}

template<typename TF, typename ... TR>
void log(LogLevel level, const std::string& function, const std::string& file, int line, TF const& f, TR const& ... rest)
{
	if (level == llInfo)
	{
		std::cout << "[Info] In " << function << " (" << file << ":" << line << "): ";
		log(std::cout, f, rest...);
		std::cout << std::endl;
	}
	else if (level == llWarn)
	{
		std::cout << "[Warn] In " << function << " (" << file << ":" << line << "): ";
		log(std::cout, f, rest...);
		std::cout << std::endl;
	}
	else if (level == llError)
	{
		std::cerr << "[Error] In " << function << " (" << file << ":" << line << "): ";
		log(std::cerr, f, rest...);
		std::cerr << std::endl;
	}
}

#define LOG_INFO(...) log(llInfo, __func__, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_WARN(...) log(llWarn, __func__, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_ERROR(...) log(llError, __func__, __FILE__, __LINE__, __VA_ARGS__)

#define LOG_ERROR_SDL(s) log(llError, __func__, __FILE__, __LINE__, s, ": ", SDL_GetError());