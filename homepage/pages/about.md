Title: About
order: 1

The ethic commission system (ECS) is a Webservice supporting Clinical Trials approval, monitoring and the electronic management of the related data. 

ECS constitutes an web-based, easily expendable open-source software solution, with manual and automatic quality control (audit protocol and track change). Its main features are online data input, reading of uploaded documents, generation of pdf documents from data input, flexible workflow and safe long-term data storage in encrypted form. Checklists are presented to external and internal reviewers and integrated into the session workflow. ECS generates session agenda and session protocols from data input and has an Email-linked internal communication system. The votes of the EC are digitally signed by the chair and automatically sent to the concerned parties. The workflow concerning post-vote issues allows upload of amendments, notifications and all safety-related reporting. Reminder functions support the investigators.

### Installation and Usage

See [Installation/Usage](installationusage.html) on how to install/operate the ecs and for users how to use the ecs.

### Development

The system is composed of a Python/Django web application using Postgres as the database on the base of Ubuntu Linux. It is currently available in German language, but could be extended to support other languages.

See [Development](development.html) for Sourcecode for ECS, ECS-Appliance and Interface documentation.

### License

ECS is a a joint initiative of five universities in Austria.
After the initial ecs version was open sourced by the medical university of vienna in 2012, 
a followup in 2016 broadend the ecs application to a more general audience.

```
Copyright 2019  Medizinische Universität Wien
Copyright 2019  Medizinische Universität Innsbruck
Copyright 2019  Medizinische Universität Graz
Copyright 2019  Johannes Kepler Universität Linz
Copyright 2019  Karl Landsteiner Privatuniversität für Gesundheitswissenschaften
Copyright 2019  Land Salzburg

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

for full license see https://github.com/ecs-org/ecs/blob/master/LICENSE

```