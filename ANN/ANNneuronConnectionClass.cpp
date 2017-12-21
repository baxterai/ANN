/*******************************************************************************
 *
 * This file is part of BAIPROJECT.
 *
 * BAIPROJECT is licensed under the GNU Affero General Public License
 * version 3, as published by the Free Software Foundation. The use of
 * intermediary programs or interfaces including file i/o is considered
 * remote network interaction. This does not imply such arrangements
 * do not constitute derivative works.
 *
 * BAIPROJECT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU Affero General Public License
 * version 3 along with BAIPROJECT.  If not, see <http://www.gnu.org/licenses/>
 * for a copy of the AGPLv3 License.
 *
 *******************************************************************************/

/*******************************************************************************
 *
 * File Name: ANNANNneuronConnectionClass.cpp
 * Author: Richard Bruce Baxter - Copyright (c) 2005-2017 Baxter AI (baxterai.com)
 * Project: Artificial Neural Network (ANN)
 * Project Version: 3m9a 16-December-2017
 * Comments:
 *
 *******************************************************************************/

#include "ANNneuronConnectionClass.hpp"

/************************************************************ Neural Network Class Definitions* *****************************************************/


ANNneuronConnection::ANNneuronConnection(void)
{
	frontNeuronID = 0;

	weight = 0.0;		//this value must be initialised explicity
	storedWeight = 0.0; 	//this value must be initialised explicity
	#ifdef ANN_ALGORITHM_MEMORY_NETWORK
	memoryTraceConnection = false;
	memoryTrace = 0.0;
	storedMemoryTrace = 0.0;
	#endif
	#ifdef ANN_ALGORITHM_CLASSIFICATION_NETWORK
	idealValue = 0.0;	//this value must be initialised explicity
	#endif

	#ifdef ANN_ALGORITHM_GIA_NEURAL_NETWORK
	GIAconnectionType = GIA_ANN_CONNECTION_TYPE_UNDEFINED;
	GIAalreadyParsed = false;
	GIAbidirectionalSynapse = false;
	#endif
	
	frontNeuron = NULL;
	backNeuron = NULL;
}

ANNneuronConnection::~ANNneuronConnection(void)
{
	if(frontNeuron != NULL)
	{
		delete frontNeuron;
	}

	/*
	if(backNeuron != NULL)
	{
		delete backNeuron;
	}
	*/

	//do not delete neurons in this destructor
}

/************************************************************ End Neural Network Class Definitions* *************************************************/


