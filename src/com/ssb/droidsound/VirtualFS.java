package com.ssb.droidsound;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import android.util.Log;

public class VirtualFS {

	static final int TYPE_FILE = 1;
	static final int TYPE_DIR = 2;
	static final int TYPE_REMOTE = 3;
	static final int TYPE_REFERENCE = 4;

	private static final String TAG = "VirtualFS";

	public static abstract class Node {
		
		
		abstract String getName();
		int getType() {
			return TYPE_DIR;
		}
		Node getChild(int pos) {
			return null;
		}
		int getChildCount() {
			return 0;
		}
		
		long getSize() {
			return 0;
		}
		InputStream read() throws IOException
		{
			throw new IOException("Unimplemented read()");
		}
		
		abstract Node getParent();
		
		File getFile() throws IOException {
			
			byte [] buffer = new byte [8192];
			InputStream in = read();
			int size;
			
			File f = File.createTempFile("node", null);
			f.deleteOnExit();
			FileOutputStream fos = new FileOutputStream(f);
			BufferedOutputStream bos = new BufferedOutputStream(fos, buffer.length);					
			while ((size = in.read(buffer)) != -1) {
				bos.write(buffer, 0, size);
			}
			bos.flush();
			bos.close();
			
			return f;
		}
		
		public String pathName() {
			if(getParent() != null)
				return getParent().pathName() + "/" + getName();
			else
				return "";
		}
		
		public Node resolvePath(String path) {
			
			if(path.length() > 0 && path.charAt(0) == '/') {
				path = path.substring(1);
			}
			
			int slash = path.indexOf('/');
			String head, rest;
			if(slash == -1) {
				head = rest = path;
			} else {
				head = path.substring(0, slash);
				rest = path.substring(slash + 1);
			}
			
			Log.v(TAG, head + " : " + rest);

			for(int i = 0; i < getChildCount(); i++) {
				Node n = getChild(i);
				if(n.getName().compareTo(head) == 0) {
					if(slash == -1) {
						return n;
					} else {
						return n.resolvePath(rest);
					}
				}
			}

			return null;
		}

	};
	
	static public class ReferenceNode extends Node {

		private Node mTarget;
		private String mName;
		private Node mParent;
		
		ReferenceNode(Node target, String name, Node parent) {
			mParent = parent;
			mName = name;
			mTarget = target;
		}
		
		@Override
		Node getParent() {
			return mParent;
		}
		
		@Override
		String getName() {
			return mName;
		}
		
		@Override
		Node getChild(int pos) {
			return mTarget.getChild(pos);
		}
		
		
		
	}
	
	static public class FileSystemNode extends Node {
		
		private File mRoot;
		private String mName;
		private File [] files;
		private Node mParent;
		
		public FileSystemNode(File f, String name, Node parent) {
			mRoot = f;
			mName = name;
			mParent = parent;
			if(mName == null) {
				mName = f.getName();
			}
			files = mRoot.listFiles();
			if(files != null) {
				Arrays.sort(files);
			}
		}

		@Override
		public Node getChild(int pos) {
			return new FileSystemNode(files[pos], null, this);
		}

		@Override
		public int getChildCount() {
			if(files == null)
				return 0;
			else
				return files.length;
		}
		
		public Node getParent() {
			return mParent;
		}
		
		@Override
		public long getSize() {
			return mRoot.length();
		}

		@Override
		public int getType() {
			if(mRoot.isDirectory())
				return TYPE_DIR;
			else
				return TYPE_FILE;
		}

		@Override
		public InputStream read() throws IOException {
			try {
				return  new FileInputStream(mRoot);
			} catch (FileNotFoundException e) {
				throw new IOException();
			}
		}

		@Override
		public String getName() {
			return mName;
		}
		
		@Override
		File getFile() throws IOException {
			return mRoot;
		}

	};
	
	private class RootNode extends Node {

		List<Node> children;
		
		RootNode() {
			children = new ArrayList<Node>();
		}
		
		@Override
		public Node getChild(int pos) {
			return children.get(pos);
		}

		@Override
		public int getChildCount() {
			return children.size();
		}

		@Override
		public String getName() {
			return "";
		}
		
		@Override
		public Node getParent() {
			return null;
		}
	}

	private RootNode mRootNode;;
	
	void registerNode(Node node) {
		
		mRootNode.children.add(node);
		
		/*
		Node [] newch = new Node [mRootNode.children.length + 1] ;
		for(int i=0; i<newch.length-1; i++) {
			newch[i] = mRootNode.children[i]; 
		}
		newch[newch.length-1] = node;
		mRootNode.children = newch;*/
	}
	
	void registerPath(String name, String path) {
		
		Node n = new FileSystemNode(new File(path), name, mRootNode);
		registerNode(n);
	}

	VirtualFS() {
		mRootNode = new RootNode();
	}

	public Node getRoot() {
		return mRootNode;
	}
	

	public Node resolvePath(String path) {
		Log.v(TAG, "Trying to resolve " + path);
		return mRootNode.resolvePath(path);
	}

	
}
