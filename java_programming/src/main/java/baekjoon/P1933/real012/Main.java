package baekjoon.P1933.real012;

import java.io.*;
import java.util.*;

class Building{
    int x;
    int h;

    public Building(int x, int h) {
        this.x = x;
        this.h = h;
    }
}

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static Scanner sc = new Scanner(System.in);
    public static StringTokenizer st;
    public static List<Building> buildingList = new ArrayList<Building>();

    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int lx = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            int rx = Integer.parseInt(st.nextToken());
            buildingList.add(new Building(lx, h));
            buildingList.add(new Building(rx, -h));
        }

        Collections.sort(buildingList, new Comparator<Building>() {
            @Override
            public int compare(Building o1, Building o2) {
                if (o1.x == o2.x) {
                    return o2.h - o1.h;
                }
                return o1.x - o2.x;
            }
        });

        TreeMap<Integer, Integer> tm = new TreeMap<Integer, Integer>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });

        List<Building> ansList = new ArrayList<Building>();
        for (int i = 0; i < buildingList.size(); i++) {
            Building cur = buildingList.get(i);

            if (cur.h > 0) {
                tm.put(cur.h, tm.getOrDefault(cur.h, 0) + 1);
            } else {
                int key = -cur.h;
                int val = tm.get(key);
                if (val == 1) {
                    tm.remove(-cur.h);
                } else {
                    tm.put(key, val - 1);
                }
            }

            if (tm.size() == 0) {
                ansList.add(new Building(cur.x, 0));
                continue;
            }

            ansList.add(new Building(cur.x, tm.firstKey()));
        }

        bw.write(ansList.get(0).x + " " + ansList.get(0).h + " ");
        int prev = ansList.get(0).h;
        for (int i = 1; i < ansList.size(); i++) {
            if (prev != ansList.get(i).h) {
                bw.write(ansList.get(i).x + " " + ansList.get(i).h + " ");
                prev = ansList.get(i).h;
            }
        }

        bw.write("\n");
        bw.flush();
    }
}