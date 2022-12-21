#include<linux/kernel.h>
#include<linux/syscalls.h>
#include<module.h>


#define __NR_details_print 287
SYSCALL_DEFINE1(detail_print, pid_t, pid)
{
  struct task_struct *task;

  /* Get the task struct of the given process */
  task = pid_task(find_vpid(pid), PIDTYPE_PID);

  /* Print the pid, user_id, pgid, and command path of the process */
  printk("pid: %d\n", task->pid);
  printk("user_id: %d\n", task->cred->uid.val);
  printk("pgid: %d\n", task->group_leader->pid);
  printk("command path: %s\n", task->comm);

  return 0;
}
