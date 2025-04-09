import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String txt = br.readLine().replaceAll("[0-9]", "");
		String pat = br.readLine();
		int[] prefixTable = buildPrefixTable(pat);
		System.out.println(kmpSearch(prefixTable, txt, pat) ? 1 : 0);
	}

	private static boolean kmpSearch(int[] prefixTable, String txt, String pat) {
		int j = 0;
		for (int i = 0; i < txt.length(); i++) {
			while (j > 0 && txt.charAt(i) != pat.charAt(j))
				j = prefixTable[j - 1];
			if (txt.charAt(i) == pat.charAt(j)) {
				j++;
				if (j == pat.length())
					return true;
			}
		}
		return false;
	}

	private static int[] buildPrefixTable(String pat) {
		int[] prefixTable = new int[pat.length()];
		int j = 0;
		for (int i = 1; i < pat.length(); i++) {
			while (j > 0 && pat.charAt(i) != pat.charAt(j))
				j = prefixTable[j - 1];
			if (pat.charAt(i) == pat.charAt(j))
				prefixTable[i] = ++j;
		}
		return prefixTable;
	}
}
