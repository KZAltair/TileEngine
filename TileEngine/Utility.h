#pragma once

inline int RoundFloatToInt(float value)
{
	int Result = (int)(value + 0.5f);
	return Result;
}