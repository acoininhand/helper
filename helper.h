//============================================================================
// Name        : helper.h
// Author      : Deepika
// Version     :
// Copyright   : Your copyright notice
// Description : Header file for hepler application
//============================================================================


#include <bits/stdc++.h>
#include <fstream>
#include <unordered_map>
using namespace std;


#define ALARM 		"10"
#define AVC 		"11"
#define CREATE		"44"
#define CREATE_RES	"24"
#define DELETE		"46"
#define DELETE_RES	"26"
#define SET 		"48"
#define SET_RES		"28"
#define GET 		"49"
#define GET_RES		"29"

#define CLS_NAME 0
#define TYPE_INT 1
#define TYPE_HEX 2


unordered_map <string, string> m = {
		{ALARM, "Alarm"},
		{AVC, "Attribute Value Change"},
		{CREATE, "Create"},
		{CREATE_RES, "Create Response"},
		{DELETE, "Delete"},
		{DELETE_RES, "Delete Response"},
		{SET,"Set"},
		{SET_RES, "Set Response"},
		{GET, "Get"},
		{GET_RES, "Get Response"},
		{"4b", "Get All Alarms"},
		{"2b", "Get All Alarms Response"},
		{"4c", "Get All Alarms Next"},
		{"2c", "Get All Alarms Next Response"},
		{"4d", "Mib Upload"},
		{"2d", "Mib Upload Response"},
		{"4e", "Mib Upload Next"},
		{"2e", "Mib Upload Next Response"},
		{"4f", "MIB Reset"},
		{"2f", "MIB Reset Response"},
		{"58", "Synchronize Time"},
		{"38", "Synchronize Time Response"}
};


typedef struct{
	string name;
	int attr_type;
	int size;
}attribute_struct;

map<int, vector<attribute_struct> > class_map ={
		{2, {
				{"ONU data", CLS_NAME, 0},
				{"MIB data sync", TYPE_INT, 1}
			}
		},
		{5, {
				{"Cardholder"	, CLS_NAME, 0},
				{"ActualPlugInUnitType", TYPE_INT, 1},
				{"ExpectedPlugInUnitType", TYPE_INT, 1},
				{"ExpectedPortCount", TYPE_INT, 1},
				{"ExpectedEquipmentId", TYPE_HEX, 20},
				{"ActualEquipmentId", TYPE_HEX, 20},
				{"ProtectionProfilePointer", TYPE_INT, 1},
				{"InvokeProtectionSwitch", TYPE_INT, 1},
				{"AlarmReportingControl", TYPE_HEX, 1},
				{"AlarmReportingControlInterval", TYPE_INT, 1}
			}
		},
		{6, {
				{"Circuit pack"	, CLS_NAME, 0},
				{"Type", TYPE_INT, 1},
				{"NumberOfPorts", TYPE_INT, 1},
				{"SerialNumber", TYPE_HEX, 8},
				{"Version", TYPE_HEX, 14},
				{"VendorId", TYPE_HEX, 4},
				{"AdministrativeState", TYPE_INT, 1},
				{"OperationalState", TYPE_INT, 1},
				{"BridgedIpInd", TYPE_INT, 1},
				{"EquipmentId", TYPE_HEX, 20},
				{"CardConfiguration", TYPE_INT, 1},
				{"TotalTcontBufferNumber", TYPE_INT, 1},
				{"TotalPriorityQueueNumber", TYPE_INT, 1},
				{"TotalTrafficSchedulerNumber", TYPE_INT, 1},
				{"PowerShedOverride", TYPE_INT, 4},
			}
		},
		{7, {
				{"Software image", CLS_NAME, 0},
				{"Version", TYPE_HEX, 14},
				{"IsCommitted", TYPE_INT, 1},
				{"IsActive", TYPE_INT, 1},
				{"IsValid", TYPE_INT, 1},
				{"ProductCode", TYPE_HEX, 25},
				{"ImageHash", TYPE_HEX, 16}
			}
		},
		{11, {
				{"PptpEthernetUni", CLS_NAME, 0},
				{"ExpectedType", TYPE_INT, 1},
				{"SensedType", TYPE_INT, 1},
				{"AutoDetectionConfiguration", TYPE_INT, 1},
				{"LoopbackConfiguration", TYPE_INT, 1},
				{"AdministrativeState", TYPE_INT, 1},
				{"OperationalState", TYPE_INT, 1},
				{"ConfigurationInd", TYPE_INT, 1},
				{"MaxFrameSize", TYPE_INT, 2},
				{"DteDceInd", TYPE_INT, 1},
				{"PauseTime", TYPE_INT, 2},
				{"BridgedIpInd", TYPE_INT, 1},
				{"AlarmReportingControl", TYPE_HEX, 1},
				{"AlarmReportingControlInterval", TYPE_INT, 1},
				{"PppoeFilter", TYPE_HEX, 1},
				{"PowerControl", TYPE_HEX, 1}
			}
		},
		{45, {
				{"Mac Bridge Service Profile", CLS_NAME, 0},
				{"SpanningTree", TYPE_HEX, 1},
				{"Learning", TYPE_HEX, 1},
				{"PortBridging", TYPE_HEX, 1},
				{"Priority", TYPE_INT, 2},
				{"MaxAge", TYPE_INT, 2},
				{"HelloTime", TYPE_INT, 2},
				{"ForwardDelay", TYPE_INT, 2},
				{"UnknownMacAddressDiscard", TYPE_HEX, 1},
				{"MacLearningDepth", TYPE_INT, 1},
				{"DynamicFilteringAgeingTime", TYPE_INT, 4}
			}
		},
		{46, {
				{"Mac Bridge Config Data", CLS_NAME, 0},
				{"MacAddress", TYPE_HEX, 6},
				{"Priority", TYPE_INT, 2},
				{"DesignatedRoot", TYPE_HEX, 6},
				{"RootPathCost", TYPE_INT, 4},
				{"PortCount", TYPE_INT, 1},
				{"RootPortNum", TYPE_INT, 2},
				{"HelloTime", TYPE_INT, 2},
				{"ForwardDelay", TYPE_INT, 2}
			}
		},

		{47, {
				{"Mac Bridge Port Config Data", CLS_NAME, 0},
				{"BridgeId", TYPE_INT, 2},
				{"PortNum", TYPE_INT, 1},
				{"TpType", TYPE_INT, 1},
				{"TpPointer", TYPE_INT, 2},
				{"Priority", TYPE_INT, 2},
				{"PathCost", TYPE_INT, 2},
				{"SpanningTree", TYPE_HEX, 1},
				{"EncapMethod", TYPE_INT, 1},
				{"LanFcs", TYPE_INT, 1},
				{"MacAddress", TYPE_HEX, 6},
				{"OutTdPointer", TYPE_INT, 2},
				{"InTdPointer", TYPE_INT, 2},
				{"MacLearningDepth", TYPE_INT, 1}
			}
		},

		{53, {
				{"PptpPotsUni"	, CLS_NAME, 0},
				{"AdministrativeState", TYPE_INT, 1},
				{"InterworkingTpPointer", TYPE_INT, 2},
				{"AlarmReportingControl", TYPE_HEX, 1},
				{"AlarmReportingControlInterval", TYPE_INT, 1},
				{"Impedance", TYPE_INT, 1},
				{"TransmissionPath", TYPE_INT, 1},
				{"RxGain", TYPE_INT, 1},
				{"TxGain", TYPE_INT, 1},
				{"OperationalState", TYPE_INT, 1},
				{"HookState", TYPE_INT, 1},
				{"PotsHoldoverTime", TYPE_INT, 2},
				{"NominalFeedVoltage", TYPE_INT, 1},
				{"LossOfSoftswitch", TYPE_INT, 1}
			}
		},
		{134, {
				{"IP host config data", CLS_NAME, 0},
				{"IP options", TYPE_HEX, 1},
				{"MAC address", TYPE_HEX, 6},
				{"Onu identifier", TYPE_HEX, 25},
				{"IP address", TYPE_INT, 4},
				{"Mask", TYPE_HEX, 4},
				{"Gateway", TYPE_HEX, 4},
				{"Primary DNS", TYPE_HEX, 4},
				{"Secondary DNS", TYPE_HEX, 4},
				{"Current address", TYPE_HEX, 4},
				{"Current mask", TYPE_HEX, 4},
				{"Current gateway", TYPE_HEX, 4},
				{"Current primary DNS", TYPE_HEX, 4},
				{"Current secondary DNS", TYPE_HEX, 4},
				{"Domain name",TYPE_HEX , 25},
				{"Host name", TYPE_HEX , 25},
				{"Relay agent options", TYPE_HEX, 2}
			}
		},
		{171, {
				{"Extended Vlan Tagging Operation Configuration Data", CLS_NAME, 0},
				{"AssociationType", TYPE_INT, 1},
				{"ReceivedFrameVlanTaggingOperationTableMaxSize", TYPE_INT, 2},
				{"InputTpid", TYPE_INT, 2},
				{"OutputTpid", TYPE_INT, 2},
				{"DownstreamMode", TYPE_INT, 1},
				{"ReceivedFrameVlanTaggingOperationTable", TYPE_HEX, 16},
				{"AssociatedManagedEntityPointer", TYPE_INT, 2},
				{"DscpToPBitMapping", TYPE_HEX, 24}
			}
		},
		{244, {
				{"Gpsu Info", CLS_NAME, 0},
				{"GpsuStatus", TYPE_INT, 1},
				{"ChargeFlags", TYPE_INT, 1},
				{"AlarmFlags", TYPE_HEX, 3},
				{"VendorCode", TYPE_HEX, 6},
				{"SerialNumber", TYPE_HEX, 13}
			}
		},
		{245, {
				{"Gpsu Pm", CLS_NAME, 0},
				{"IntervalEndTime", TYPE_INT, 1},
				{"ThresholdDataId", TYPE_INT, 2},
				{"Battery_voltage", TYPE_INT, 4},
				{"Charging_current", TYPE_INT, 4},
				{"Max_battery_voltage", TYPE_INT, 4},
				{"Max_charging_current", TYPE_INT, 4},
				{"Solar_panel_voltage", TYPE_INT, 4},
				{"Solar_panel_current", TYPE_INT, 4},
				{"Smps_voltage", TYPE_INT, 4},
				{"Smps_current", TYPE_INT, 4},
				{"Load_voltage", TYPE_INT, 4},
				{"Load_current", TYPE_INT, 4}
			}
		},
		{256, {
				{"ONU-G ", CLS_NAME, 0},
				{"VendorId", TYPE_INT, 4},
				{"Version", TYPE_HEX, 14},
				{"SerialNumber", TYPE_HEX, 8},
				{"TrafficManagementOption", TYPE_INT, 1},
				{"Deprecated", TYPE_INT, 1},
				{"BatteryBackup", TYPE_INT, 1},
				{"AdministrativeState", TYPE_INT, 1},
				{"OperationalState", TYPE_INT, 1},
				{"OnuSurvivalTime", TYPE_INT, 1},
				{"LogicalOnuId", TYPE_HEX, 24},
				{"LogicalPassword", TYPE_HEX, 12},
				{"CredentialsStatus", TYPE_INT, 1},
				{"ExtendedTCLayerOptions", TYPE_INT, 2}
			}
		},
		{257, {
				{"ONU2-G ", CLS_NAME, 0},
				{"EquipmentId", TYPE_HEX, 20},
				{"OmccVersion", TYPE_INT, 1},
				{"VendorProductCode", TYPE_INT, 2},
				{"SecurityCapability", TYPE_INT, 1},
				{"SecurityMode", TYPE_INT, 1},
				{"TotalPriorityQueueNumber", TYPE_INT, 2},
				{"TotalTrafficSchedulerNumber", TYPE_INT, 1},
				{"Deprecated", TYPE_INT, 1},
				{"TotalGemPortIdNumber", TYPE_INT, 2},
				{"SysUpTime", TYPE_INT, 4},
				{"ConnectivityCapability", TYPE_INT, 2},
				{"CurrentConnectivityMode", TYPE_INT, 1},
				{"QosConfigFlexibiltiy", TYPE_INT, 2},
				{"PriorityQueueScaleFactor", TYPE_INT, 2}
			}
		},
		{262, {
				{"T-CONT", CLS_NAME, 0},
				{"AllocId", TYPE_INT, 2},
				{"Deprecated", TYPE_INT, 1},
				{"Policy", TYPE_INT, 1}
			}
		},
		{263, {
				{"ANI-G", CLS_NAME, 0},
				{"SrIndication", TYPE_HEX, 1},
				{"TotalTcontNumber", TYPE_INT, 2},
				{"GemBlockLength", TYPE_INT, 2},
				{"PiggybackDbaReporting", TYPE_INT, 1},
				{"Deprecated", TYPE_INT, 1},
				{"SfThreshold", TYPE_INT, 1},
				{"SdThreshold", TYPE_INT, 1},
				{"AlarmReportingControl", TYPE_INT, 1},
				{"AlarmReportingControlInterval", TYPE_INT, 1},
				{"OpticalSignalLevel", TYPE_INT, 2},
				{"LowerOptivalThreshold", TYPE_INT, 1},
				{"UpperOptivalThreshold", TYPE_INT, 1},
				{"OntResponseTime", TYPE_INT, 2},
				{"TransmitOpticalLevel", TYPE_INT, 2},
				{"LowerTransmitPowerThreshold", TYPE_INT, 1},
				{"UpperTransmitPowerThreshold", TYPE_INT, 1}
			}
		},
		{264, {
				{"UNI-G", CLS_NAME, 0},
				{"Deprecated", TYPE_INT, 2},
				{"AdministrativeState", TYPE_INT, 1},
				{"ManagementCapability", TYPE_INT, 1},
				{"NonOmciManagementId", TYPE_INT, 2},
				{"RelayAgentOptions", TYPE_INT, 2}
			}
		},
		{268, {
				{"Gem Port Network Ctp", CLS_NAME, 0},
				{"PortIdValue", TYPE_INT, 2},
				{"TContPointer", TYPE_INT, 2},
				{"Direction", TYPE_INT, 1},
				{"UpstreamTrafficManagementPointer", TYPE_INT, 2},
				{"UpstreamTrafficDescriptorProfilePointer", TYPE_INT, 2},
				{"UniCounter", TYPE_INT, 1},
				{"DownstreamPriorityQueuePointer", TYPE_INT, 2},
				{"EncryptionState", TYPE_INT, 1},
				{"DownstreamTrafficDescriptorProfilePointerr", TYPE_INT, 2}
			}
		},

		{277, {
				{"Priority Queue-G", CLS_NAME, 0},
				{"QueueConfigurationOption", TYPE_INT, 2},
				{"MaxQueueSize", TYPE_INT, 2},
				{"AllocatedQueueSize", TYPE_INT, 2},
				{"DiscardBlockCounterResetInterval", TYPE_INT, 2},
				{"BufferOverFlowsDiscardBlockThreshold", TYPE_INT, 2},
				{"RelatedPort", TYPE_INT, 4},
				{"TrafficSchedulerGPointer", TYPE_INT, 2},
				{"Weight", TYPE_INT, 1},
				{"BackPressureOperation", TYPE_INT, 2},
				{"BackPressureTime", TYPE_INT, 4},
				{"BackPressureOccurQueueThreshold", TYPE_INT, 2},
				{"BackPressureOccurQueueThreshold", TYPE_INT, 2},
				{"PacketDropQueueThresholds", TYPE_HEX, 8},
				{"PacketDropMaxP", TYPE_INT, 2},
				{"QueueDropWQ", TYPE_INT, 1},
				{"DropPrecedenceColourMarking", TYPE_INT, 1}
			}
		},
		{281, {
				{"Multicast Gem Interworking Tp", CLS_NAME, 0},
				{"GemPortNetworkCtpConnPointer", TYPE_INT, 2},
				{"InterworkingOption", TYPE_INT, 1},
				{"ServiceProfilePointer", TYPE_INT, 2},
				{"InterworkingTermPointPointer", TYPE_INT, 2},
				{"PptpCounter", TYPE_INT, 1},
				{"OperationalState", TYPE_INT, 1},
				{"GalProfilePointer", TYPE_INT, 2},
				{"GalLoopbackConfiguration", TYPE_INT, 1},
				{"MulticastAddressField", TYPE_HEX, 24}
			}
		},
		{296, {
				{"Ethernet Pm History Data 3", CLS_NAME, 0},
				{"IntervalEndTime", TYPE_INT, 1},
				{"ThresholdDataId", TYPE_INT, 2},
				{"DropEvents", TYPE_INT, 4},
				{"Octets", TYPE_INT, 4},
				{"Packets", TYPE_INT, 4},
				{"BroadcastPackets", TYPE_INT, 4},
				{"MulticastPackets", TYPE_INT, 4},
				{"UndersizePackets", TYPE_INT, 4},
				{"Fragments", TYPE_INT, 4},
				{"Jabbers", TYPE_INT, 4},
				{"Packets64Octets", TYPE_INT, 4},
				{"Packets127Octets", TYPE_INT, 4},
				{"Packets255Octets", TYPE_INT, 4},
				{"Packets511Octets", TYPE_INT, 4},
				{"Packets1023Octets", TYPE_INT, 4},
				{"Packets1518Octets", TYPE_INT, 4}
			}
		},
		{309, {
				{"Multicast Operations Profile", CLS_NAME, 0},
				{"IgmpVersion", TYPE_INT, 1},
				{"IgmpFunction", TYPE_INT, 1},
				{"ImmediateLeave", TYPE_INT, 1},
				{"UpstreamIgmpTci", TYPE_INT, 2},
				{"UpstreamIgmpTagControl", TYPE_INT, 1},
				{"UpstreamIgmpRate", TYPE_INT, 4},
				{"DynamicAccessControlListTable", TYPE_HEX, 24},
				{"StaticAccessControlListTable", TYPE_HEX, 24},
				{"LostGroupsListTable", TYPE_HEX, 10},
				{"Robustness", TYPE_INT, 1},
				{"QuerierIpAddress", TYPE_INT, 4},
				{"QueryInterval", TYPE_INT, 4},
				{"QueryMaxResponseTime", TYPE_INT, 4},
				{"LastMemberQueryInterval", TYPE_INT, 4},
				{"UnauthorizedJoinRequestBehaviour", TYPE_INT, 1},
				{"DownstreamIgmpTci", TYPE_HEX, 3}
			}
		},
		{321, {
				{"Downstream Ethernet Frame Pm", CLS_NAME, 0},
				{"IntervalEndTime", TYPE_INT, 1},
				{"ThresholdDataId", TYPE_INT, 2},
				{"DropEvents", TYPE_INT, 4},
				{"Octets", TYPE_INT, 4},
				{"Packets", TYPE_INT, 4},
				{"BroadcastPackets", TYPE_INT, 4},
				{"MulticastPackets", TYPE_INT, 4},
				{"CrcErroredPackets", TYPE_INT, 4},
				{"UndersizePackets", TYPE_INT, 4},
				{"OversizePackets", TYPE_INT, 4},
				{"Packets64Octets", TYPE_INT, 4},
				{"Packets127Octets", TYPE_INT, 4},
				{"Packets255Octets", TYPE_INT, 4},
				{"Packets511Octets", TYPE_INT, 4},
				{"Packets1023Octets", TYPE_INT, 4},
				{"Packets1518Octets", TYPE_INT, 4}
			}
		},
		{322, {
				{"Upstream Ethernet Frame Pm", CLS_NAME, 0},
				{"IntervalEndTime", TYPE_INT, 1},
				{"ThresholdDataId", TYPE_INT, 2},
				{"DropEvents", TYPE_INT, 4},
				{"Octets", TYPE_INT, 4},
				{"Packets", TYPE_INT, 4},
				{"BroadcastPackets", TYPE_INT, 4},
				{"MulticastPackets", TYPE_INT, 4},
				{"CrcErroredPackets", TYPE_INT, 4},
				{"UndersizePackets", TYPE_INT, 4},
				{"OversizePackets", TYPE_INT, 4},
				{"Packets64Octets", TYPE_INT, 4},
				{"Packets127Octets", TYPE_INT, 4},
				{"Packets255Octets", TYPE_INT, 4},
				{"Packets511Octets", TYPE_INT, 4},
				{"Packets1023Octets", TYPE_INT, 4},
				{"Packets1518Octets", TYPE_INT, 4}
			}
		},
		{329, {
				{"Virtual Ethernet Interface Point", CLS_NAME, 0},
				{"AdministrativeState", TYPE_INT, 1},
				{"OperationalState", TYPE_INT, 1},
				{"InterDomainName", TYPE_HEX, 25},
				{"TcpUdpPointer", TYPE_INT, 2},
				{"IanaAssignedPort", TYPE_INT, 2}
			}
		},
		{425, {
				{"Ethernet FrameExtended PM 64 Bit", CLS_NAME, 0},
				{"IntervalEndTime", TYPE_INT, 1},
				{"ControlBlock", TYPE_HEX, 16},
				{"DropEvents", TYPE_INT, 8},
				{"Octets", TYPE_INT, 8},
				{"Frames", TYPE_INT, 8},
				{"BroadcastFrames", TYPE_INT, 8},
				{"MulticastFrames", TYPE_INT, 8},
				{"CrcErroredFrames", TYPE_INT, 8},
				{"UndersizeFrames", TYPE_INT, 8},
				{"OversizeFrames", TYPE_INT, 8},
				{"Frames64Octets", TYPE_INT, 8},
				{"Frames127Octets", TYPE_INT, 8},
				{"Frames255Octets", TYPE_INT, 8},
				{"Frames511Octets", TYPE_INT, 8},
				{"Frames1023Octets", TYPE_INT, 8},
				{"Frames1518Octets", TYPE_INT, 8}
			}
		},
		{65284, {
				{"Sfp Info", CLS_NAME, 0},
				{"SfpType", TYPE_INT, 1},
				{"VendorName", TYPE_HEX, 16},
				{"VendorPartNo", TYPE_HEX, 16},
				{"VendorRev", TYPE_HEX, 4},
				{"VendorSerialNumber", TYPE_HEX, 16}
			}
		},
		{65285, {
				{"Sfp Info Pm", CLS_NAME, 0},
				{"IntervalEndTime", TYPE_INT, 1},
				{"ThresholdDataId", TYPE_INT, 2},
				{"RxPower", TYPE_INT, 4},
				{"TxPower", TYPE_INT, 4},
				{"Temperature", TYPE_INT, 4},
				{"Current", TYPE_INT, 4},
				{"Voltage", TYPE_INT, 4}
			}
		}

};

//{2, {
//		{"mibName", CLS_NAME, 0},
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, },
//		{"", TYPE_INT, }
//	}
//},
