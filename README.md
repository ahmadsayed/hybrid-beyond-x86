# Build a Hybrid Application beyond x86, using buildah and podman


## Why do we need to consider Multiarch hybrid applications

Enterprises and Large system used to run on Mainframe, a large computer with a large amount of memory, but with increasing needs of Personal Computer (a.k.a) Microcomputer, more CPU started to Mass produced to fit inside a box that lay on the Desktop.

The Microcomputer CPUs started to make their way to Enterprise applications. With the introduction of the distributed system, the x86 machines began to dominate the Enterprise applications with the success of distributed systems. A former boss of mine, Stewart Alsop, famously the last Mainframe will be unplugged on March 15, 1996. This prediction turns out to be very wrong with IBM introducing IBM Z15 in September 2020. IBM Z and Mainframe turns out to be very much alive and striving. Running a Legacy application very reliable, and the Mainframe is packed with considerable computing power in a small footprint compared to distributed x86_64 systems.

Public Cloud and Hyperscaler become the new normal for hosting Enterprise application, with apparent domination of x86_64 ISA from Intel Xeon and AMD EPYC. Still, the demands for specialized workloads and hosting from businesses make the public cloud provider introduce different Machines such as IBM power, IBM Z, and Amazon ARM.

Nowadays, we are in the Era of 5G and IoT, with increased Edge computing demands, and we raise awareness about the environmental impact of the datacenters and increase needs. Power-efficient machines make ARM machines start to get back to the PC market and move toward Servers and Enterprise Applications.

The previous introduction is trying to demonstrate why there is a need for multiarch deployments; if you are building an application, asset, or even custom enterprise solution, you may still face a demand to deploy it on none x86 machines.

## Introducing Instruction set Architecture (ISA)



## Explore commonly used ISA and the Commercial CPU
## Options to build multiarch container images
## Explain Qemu user emulation
## Testing Environment.
   * Kubernetes Cluster on ARM64 using VMware ESXi as Hypervisor
   * Mysql on ARM64 on Arm64 Virtual Machines
   * Single node Kubernetes Cluster and Mysql on x86 VM
## Demo
   * Show how to build a multiarch container image using qemu-user-static
   * Show how MySQL replication happens between different Arch
