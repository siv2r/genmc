/*
 * GenMC -- Generic Model Checking.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you can access it online at
 * http://www.gnu.org/licenses/gpl-3.0.html.
 *
 * Author: Michalis Kokologiannakis <michalis@mpi-sws.org>
 */

#ifndef __RC11_WEAKRA_DRIVER_HPP__
#define __RC11_WEAKRA_DRIVER_HPP__

#include "GenMCDriver.hpp"

class RC11WeakRADriver : public GenMCDriver {

public:

	RC11WeakRADriver(std::unique_ptr<Config> conf, std::unique_ptr<llvm::Module> mod,
			 std::vector<Library> &granted, std::vector<Library> &toVerify,
			 clock_t start)
		: GenMCDriver(std::move(conf), std::move(mod), granted, toVerify, start) {};

	std::vector<Event> getStoresToLoc(llvm::GenericValue *addr);
	std::pair<int, int> getPossibleMOPlaces(llvm::GenericValue *addr, bool isRMW);
	std::vector<Event> getRevisitLoads(EventLabel &lab);
	std::pair<std::vector<EventLabel>, std::vector<std::pair<Event, Event> > >
		  getPrefixToSaveNotBefore(EventLabel &lab, View &before);

	bool checkPscAcyclicity();
	bool isExecutionValid();
};

#endif /* __RC11_WEAKRA_DRIVER_HPP__ */