#### Appliance Hooks

The appliance can be customized using hook scripts which should be placed under `/app/etc/hooks/{hookname}/*.sh`.

To add hook files add an entry under appliance:extra:files.
Any shellscript in a hook directory ending with ".sh" will be executed on hook trigger.

The following hooks are defined:
+ prepare-ecs.early
+ prepare-ecs.late
+ prepare-appliance.early
+ prepare-appliance.late

