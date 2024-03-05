// Emacs style mode select -*- C++ -*-
//-----------------------------------------------------------------------
//
// Copyright(C) 2001 Simon Howard
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser 
// General Public License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
//
//--------------------------------------------------------------------------
//
// PC Speaker Code
//
//-----------------------------------------------------------------------

#ifndef __PCSOUND_H__
#define __PCSOUND_H__

//
// Initialise and Shut down
//

void Speaker_Init();
void Speaker_Shutdown();

//
// Turn speaker on and off
//

void Speaker_On();
void Speaker_Off();

// 
// Play a particular tone to the speaker
//
// count: This determines the frequency. count is 
//        the number of clock ticks between speaker
//        pulses. Hence clock_freq/count == tone 
//        frequency
//

void Speaker_Output(unsigned short count);

//
// Play a sound 
//
// This should be identical to the BASIC SOUND function
// duration = 1/18th's of a second
//

void Speaker_Sound(int freq, int duration);

#endif

