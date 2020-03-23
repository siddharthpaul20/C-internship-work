typedef unsigned int guint32;
typedef unsigned short guint16;
typedef int gint32;

struct globalHeader					// it is of size 24 bytes
{
	guint32 magicNumber;  				// 'A1B2C3D4' means the endianess is correct
	guint16 versionMajor;   	 		// major number of the file format
	guint16 versionMinor;   			// minor number of the file format
	gint32 correctionTime;	   			// correction time in seconds from UTC to local time(0)
	guint32 accuracyOfTimestampInCapture;        	// accuracy of timestamps in capture(0)
	guint32 maxLengthOfCapturedPacket;           	// max length of captured packet
	guint32 typeOfDataLink;      			// type of data link (1= ethernet)
	
	globalHeader()
	{
		magicNumber = 0;
		versionMajor = 0;
		versionMinor = 0;
		correctionTime = 0;
		accuracyOfTimestampInCapture = 0;
		maxLengthOfCapturedPacket = 0;
		typeOfDataLink = 0;
	}
};
