package com.ssb.droidsound.async;

import android.database.Cursor;
import android.os.AsyncTask;
import android.widget.CursorAdapter;

/**
 * Super simple asynchronous Cursor loading (wait in a thread until result set is
 * ready), except here normal Cursors can be used like they were asynchronously
 * loaded (they will be). Just be sure to not do any operations beforehand on the
 * Cursor, because those may imply the need to materialize the result set too early.
 * <p>
 * Remember to use db.enableWriteAheadLogging() to allow concurrent queries from
 * multiple threads on the database.
 *
 * @author alankila
 */
public class AsyncQueryResult extends AsyncTask<Void, Void, Void> {
	private final Cursor cursor;
	private final CursorAdapter cursorAdapter;

	public AsyncQueryResult(Cursor cursor, CursorAdapter cursorAdapter) {
		this.cursor = cursor;
		this.cursorAdapter = cursorAdapter;
	}

	@Override
	protected Void doInBackground(Void... params) {
		cursor.getCount();
		return null;
	}

	@Override
	protected void onPostExecute(Void result) {
		cursorAdapter.changeCursor(cursor);
	}
}