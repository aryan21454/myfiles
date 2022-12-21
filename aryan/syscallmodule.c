#include <linux/module.h>     /* Needed by all modules */
#include <linux/kernel.h>
#include<linux/syscalls.h>/* Needed for KERN_INFO */
#include <linux/init.h>       /* Needed for the macros */
  
///< The license type -- this affects runtime behavior
MODULE_LICENSE("GPL");
  
///< The author -- visible when you use modinfo
MODULE_AUTHOR("Aryan Sharma");
  
///< The description -- see modinfo
MODULE_DESCRIPTION("my modle");
  
///< The version of the module
MODULE_VERSION("0.1");
  
static int __init detail_print(void)
{
    printk(KERN_INFO "Loading hello module...\n");
    printk(KERN_INFO "Hello world\n");
    return 0;
}
 #define __NR_detail_print 452
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
static void __exit detail_print(void)
{
    printk(KERN_INFO "Goodbye Mr.\n");
}



