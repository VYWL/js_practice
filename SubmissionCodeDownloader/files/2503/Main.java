
package boj_main;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	public static MyScanner sc = new MyScanner();

	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

	}

	public static void main(String[] args) {
		char[] ch = sc.nextLine().toCharArray();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < ch.length - 1; i++) {
			sb.append(ch[i]);
			sb.append("__");
		}
		sb.append(ch[ch.length - 1]);
		out.println(sb.toString());
		out.flush();

	}

}
