package com.ssb.droidsound;

import java.net.MalformedURLException;
import java.net.URL;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;

import com.ssb.droidsound.VirtualFS.Node;

public class RemoteFS {
	
	private SAXParser saxParser;
	private URL rootURL;
	
	RemoteFS(String rooturl) throws ParserConfigurationException, SAXException, MalformedURLException {

		// The Factory knows about the available parsers
		SAXParserFactory spf = SAXParserFactory.newInstance();
		
		// Just get a parser using the default configuration
		saxParser = spf.newSAXParser();
                        
        //XMLReader xr = sp.getXMLReader();
        //MyHandler handler = new MyHandler();
        //xr.setContentHandler(MyHandler);
		
		rootURL = new URL(rooturl); 
		
	}

	
	public class Node extends VirtualFS.Node {
		
		
		Node() {
			
		}

		@Override
		String getName() {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		Node getParent() {
			// TODO Auto-generated method stub
			return null;
		}
	}
	
	
}
