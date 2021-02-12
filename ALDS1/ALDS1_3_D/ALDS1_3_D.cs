using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ALDS1_3_D
{
    class Program
    {
        static void Main(string[] args)
        {
            string cross_section;   //ífñ ê}

            cross_section = Console.ReadLine();

            if((cross_section.Length < 1) || (cross_section.Length > 20000))
            {
                Console.WriteLine("input_error!\n");
                return;
            }

            Stack<int> stack = new Stack<int>();
            Stack<Puddle> stack_puddle = new Stack<Puddle>();
            
            for (int i = 0; i < cross_section.Length; i++)
            {
                if(cross_section[i] == '\\')
                {
                    stack.Push(i);
                }
                else if(cross_section[i] == '/')
                {
                    if(stack.Count != 0)
                    {
                        //êÖÇΩÇ‹ÇËÇ™Ç≈Ç´ÇƒÇ¢ÇÈÅB Å_Å^Ç™ë∂ç›Ç∑ÇÈ
                        int popidx = stack.Pop();
                        int area = i - popidx;

                        Puddle newPuddle = new Puddle(popidx, area);

                        stack_puddle.Push(newPuddle);

                        int stack_puddle_num = stack_puddle.Count;


                        //êÖÇΩÇ‹ÇËÇÃÉ}Å[ÉW
                        Puddle topPuddle;
                        Puddle topminus1Puddle;

                        do
                        {
                            if (stack_puddle.Count < 2) break;

                            topPuddle = stack_puddle.Pop();
                            topminus1Puddle = stack_puddle.Pop();

                            if (topPuddle.Idx < topminus1Puddle.Idx)
                            {
                                int merge_area = topPuddle.Area + topminus1Puddle.Area;
                                int merge_idx = topPuddle.Idx;
                                Puddle mergePuddle = new Puddle(merge_idx, merge_area);

                                stack_puddle.Push(mergePuddle);
                            }
                            else
                            {
                                stack_puddle.Push(topminus1Puddle);
                                stack_puddle.Push(topPuddle);
                            }
                        } while (topPuddle.Idx < topminus1Puddle.Idx);
                    }
                }
            }

            int puddle_num = stack_puddle.Count;
            int puddle_total_area = 0;
            List<int> puddle_area = new List<int>();

            for(int i = 0; i < puddle_num; i++)
            {
                Puddle tmp = stack_puddle.Pop();
                puddle_total_area += tmp.Area;
                puddle_area.Add(tmp.Area);
            }

            Console.WriteLine(puddle_total_area);
            Console.Write(puddle_num);

            if(puddle_num == 0)
            {
                Console.WriteLine();
            }
            else
            {
                Console.Write(" ");
            }

            for(int i = puddle_area.Count-1; i >= 0; i--)
            {
                Console.Write(puddle_area[i]);
                if(i != 0)
                {
                    Console.Write(" ");
                }
                else
                {
                    Console.WriteLine();
                }
            }
        }
    }

    class Puddle
    {
        int idx;
        int area;

        public int Idx
        {
            get { return idx; }
            set { idx = value;}
        }
        public int Area
        {
            get { return area;}
            set { area = value;}
        }

        public Puddle(int idx, int area)
        {
            this.idx = idx;
            this.area = area;
        }
    }
}