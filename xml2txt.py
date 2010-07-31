#!/usr/bin/python

import os
import sys
from xml.dom.minidom import Document, parseString
	

def getText(node, tag) :
	nextNode = None
	tags = tag.split('/')
	for t in tags :
		#print t, node
		for c in node.childNodes :
			# print ">> ", c.nodeType
			if c.nodeType == c.ELEMENT_NODE :
				# print ">> ", c.tagName
				if c.tagName == t :
					nextNode = c
					break
		if nextNode == None :
			return ''
		node = nextNode
		nextNode = None
						
	rc = ''
	# print "Found node ", node
	for t in node.childNodes :		
		if t.nodeType == c.TEXT_NODE :
			rc += t.data
	return rc



def main(argv) :
	try :
		xmlData = open(argv[0]).read()
	except :
		xmlData = None
		
	outf = open(argv[1], 'w')
		
	groupList = {}
	eventList = {}
	
	code = 'iso8859_1'
		
	if xmlData :
		doc = parseString(xmlData)
		releases = doc.getElementsByTagName('Release')
		#print "Found %d releases" % (len(releases))
 		outf.write("[Releases]\n")

		for r in releases :
			rel = {}
			
			name = getText(r, 'Name')
			id = getText(r, 'ID')
			rating = getText(r, 'CSDbRating')
			if rating :
				rating = str(int(float(rating) * 100))
			
			gid = getText(r, 'ReleasedBy/Group/ID')
			if gid :
				group = getText(r, 'ReleasedBy/Group/Group')
				groupList[int(gid)] = group

			y = getText(r, 'ReleaseDate/Year')
			m = getText(r, 'ReleaseDate/Month')
			date = 0
			if y :
				date = int(y) * 10000
			if m :
				date += (int(m) * 100)

			 
			eid = getText(r, 'Achievement/Event/ID')
			if eid :
				event = getText(r, 'Achievement/Event/Name')
				
				if int(eid) == 7 :
					print "%s %d" % (name, date)
				
				if eventList.has_key(eid) :
					x = eventList[int(eid)]
					if x[1] == 0 :
						eventList[int(eid)] = (event, date)
				else :
					eventList[int(eid)] = (event, date)
			
			compo = getText(r, 'Achievement/Compo')
			place = getText(r, 'Achievement/Place')
						
			type = getText(r, 'ReleaseType')
			if compo :
				type = compo

			#print getText(r, 'ReleaseDate/Month')
			#print getText(r, 'Sids/HVSCPath')

			sids = r.getElementsByTagName('HVSCPath')
			fnames = []
			for s in sids :			
				fnames.append(s.firstChild.data)
				
			rel = (id, name, gid, type, str(date), eid, place, rating, ','.join(fnames))
			outf.write((u'\t'.join(rel) + "\n").encode(code))
 		
 		outf.write("[Groups]\n")
 		
		for g in groupList :
			outf.write((u"%d\t%s\n" % (g, groupList[g])).encode(code))

 		outf.write("[Events]\n")

		for e in eventList :
			x = eventList[e]
			outf.write((u"%d\t%d\t%s\n" % (e, x[1], x[0])).encode(code))

		outf.close()
						

if __name__ == "__main__":
	main(sys.argv[1:])
