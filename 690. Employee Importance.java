// https://leetcode.com/problems/employee-importance/description/

/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        HashMap<Integer, Employee> m = new HashMap<Integer, Employee>();
        for (Employee e : employees) {
            m.put(e.id, e);
        }
        int res = 0;
        Queue<Integer> q = new ArrayDeque<Integer>();
        try {
            q.add(id);
            while (!q.isEmpty()) {
                int cur = q.poll();
                res += m.get(cur).importance;
                for (Integer s : m.get(cur).subordinates) {
                    q.add(s);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return res;
    }
}
