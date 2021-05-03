/*
	This file is part of D2DX.

	Copyright (C) 2021  Bolrog

	D2DX is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	D2DX is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with D2DX.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include "IGameHelper.h"
#include "IRenderContext.h"

namespace d2dx
{
	class UnitMotionPredictor final
	{
	public:
		UnitMotionPredictor(
			_In_ const std::shared_ptr<IGameHelper>& gameHelper);

		void Update(
			_In_ IRenderContext* renderContext);

		OffsetF GetOffset(
			_In_ const D2::UnitAny* unit);

	private:
		struct UnitMotion final
		{
			int64_t lastUsedFrame = 0;
			Offset lastPos = { 0, 0 };
			Offset velocity = { 0, 0 };
			Offset predictedPos = { 0, 0 };
			Offset correctedPos = { 0, 0 };
			int64_t dtLastPosChange = 0;
		};

		std::shared_ptr<IGameHelper> _gameHelper;
		uint32_t _frame = 0;
		const D2::UnitAny* _unitPtrs[1024];
		UnitMotion _unitMotions[1024];
		int32_t _unitsCount = 0;
	};
}
