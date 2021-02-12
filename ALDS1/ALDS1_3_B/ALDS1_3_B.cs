using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ALDS_1_3_B
{
    public struct Process
    {
        public string name;
        public int time;
    }

    class Program
    {
        static void Main(string[] args)
        {
            int process_num;
            int quantum;
            Process proc = new Process();
            Queue<Process> proc_queue = new Queue<Process>();

            string inputline = Console.ReadLine();
            string[] sp_inputline = inputline.Split(' ');
            process_num = int.Parse(sp_inputline[0]);
            quantum = int.Parse(sp_inputline[1]);

            /* プロセスキューの作成 */
            for(int i = 0; i < process_num; i++)
            {
                inputline = Console.ReadLine();
                sp_inputline = inputline.Split(' ');

                proc.name = sp_inputline[0];
                proc.time = int.Parse(sp_inputline[1]);
                proc_queue.Enqueue(proc);
            }

            /* スケジューリング */
            int elapsed_time = 0;

            while(proc_queue.Count != 0)
            {
                Process target_proc = proc_queue.Dequeue();
                
                if((target_proc.time - quantum) <= 0)
                {
                    /* クオンタム時間内にプロセスが終了 */
                    elapsed_time += target_proc.time;
                    Console.WriteLine(target_proc.name + " " + elapsed_time);
                }
                else
                {
                    /* クオンタム時間内にプロセスが終了しなかった */
                    elapsed_time += quantum;
                    target_proc.time -= quantum;
                    proc_queue.Enqueue(target_proc);
                }
            }
        }
    }
}