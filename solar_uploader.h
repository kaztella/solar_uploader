/*
    midnitelogger - A data logging software for use with Midnite Solar's
                    "Classic" charge controllers over TCP 

    Copyright (C) 2015 Jason Hughes (wk_fs@skie.net)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SOL_ULDR_H
#define SOL_ULDR_H


typedef struct {
	int cid; // charge controller id number
	char ip[CC_MAX_HOST_LEN+18]; // ip address
	char name[9]; // short name
//	unsigned char alive; // alive?!
    time_t ts; //time stamp
	// socket stuff
//	int s;
//	struct hostent *hp;
//	struct sockaddr_in sa;

	// modbus registers - might as well keep these
	// we'll use this for 4100 to 4355
	float 	battery_volts;
	float		pv_volts; 			//[Volt] = (float)cclist[i].modbus_register[15]/10.0f;
	float		battery_volts_raw; 	//[Volt] = (float)cclist[i].modbus_register[175]/10.0f;
	float		pv_volts_raw; 		//[Volt] = (float)cclist[i].modbus_register[176]/10.0f;
	float		battery_amps; 		//[A] = (float)cclist[i].modbus_register[16]/10.0f;
	float		pv_amps; 				//[A] = (float)cclist[i].modbus_register[20]/10.0f;
	float		pv_voc; 				//[V] = (float)cclist[i].modbus_register[21]/10.0f;
	float		watts; 				//[W] = cclist[i].modbus_register[18];
	float		kWh_today; 			//[kWh] = (float)cclist[i].modbus_register[17]/10.0f;
	float		Ah_today; 			//[Ah] = cclist[i].modbus_register[24];
	float		ext_temp; 			//[C] = (float)cclist[i].modbus_register[31]/10.0f;
	float		int_fet_temp; 		//[C] = (float)cclist[i].modbus_register[32]/10.0f;
	float		int_pcb_temp; 		//[C] = (float)cclist[i].modbus_register[33]/10.0f;
	float		life_kWh ; 			//[kWh] =    (float)((unsigned long)cclist[i].modbus_register[25] + ((unsigned long)cclist[i].modbus_register[26]<<16))/10.0f;
	int 		life_Ah; 				//[Ah] = (unsigned long)cclist[i].modbus_register[27] + ((unsigned long)cclist[i].modbus_register[28]<<16);
	int		float_seconds_today;//[sec] = cclist[i].modbus_register[37];
	int		combochargestate; 	//[]= cclist[i].modbus_register[19];
	// last successful read
	unsigned int last_success;
} DB_DATA;


// PGresult* psql_query(PGconn *lconn, char *str);
// int load_charge_controllers(PGconn *conn);
// void connect_all();
// void gather_data_all();
// void close_all();
// int modbus_read_registers_command(int cc, int addr, int number, int offset);
// int modbus_read_registers_finish_read(int cc, int addr, int number, int offset);
// void wait_for_write_ready();
// void wait_for_data_ready();
// void write_to_db(PGconn *conn);
// void get_from_all(int offset, int count);
// void print_usage(char *pname);
// void print_local_status();

#endif
